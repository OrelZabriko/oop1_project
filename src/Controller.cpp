//-----include section-----
#include "Controller.h"

#include <iostream>
#include <thread>
#include <chrono>


//-----functions section------
//-----------------------------------------------------------------------------
void Controller::Run()
{
    OpeningMenu start_menu;

    LoadLevel levelManager;
    if (!levelManager.readAllLevels())
    {
        std::cerr << "read levels failed\n";
        return;
    }
    
    GameManager manager(levelManager.getLevel());
    
    sf::Clock clock;
    sf::Clock gameTimer;
    

    m_GameWindow.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), OPENING_WINDOW_NAME);
    m_GameWindow.setFramerateLimit(60);


    auto& backgroundMusic = ResourceManager::getInstance().GetBackgroundMusic();
    backgroundMusic.setLoop(true);
    backgroundMusic.setVolume(20.0f);
    backgroundMusic.play();  //Start the music
    

    while (m_GameWindow.isOpen())
    {
        const auto deltaTime = clock.restart();

        if (!m_startMenuState)
        {
            manager.SetStartGame(false);
            start_menu.Draw(m_GameWindow);
        }
        else
        {
            manager.SetStartGame(true);
            m_GameWindow.clear();
            manager.draw(m_GameWindow);
            m_infoBar.drawInfoBar(m_GameWindow);
        }


        if (auto event = sf::Event{}; m_GameWindow.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
            {
                m_GameWindow.close();
                break;
            }
            case sf::Event::MouseButtonPressed:
            {
                handleOpenMenuMouseClick(m_GameWindow, start_menu, levelManager);
                break;
            }
            case sf::Event::KeyPressed:
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    //manager.ResetBoard(); //in case of out the window, reset the location of the updateable object
                    m_GameWindow.clear();
                    start_menu.Draw(m_GameWindow);
                    m_startMenuState = false;
                }
                else if (event.key.code == sf::Keyboard::B)
                {
                    manager.dropBomb();
                }
                else
                {
                    handleKeyPressed(event.key.code, deltaTime, manager);
                }

                break;
            }
            }
        }
        manager.updateGuards(deltaTime);
        manager.updateBombs(deltaTime);

        manager.HandleTheCollision();
        
        m_GameWindow.display();
    }
}


//-----------------------------------------------------------------------------
void Controller::handleOpenMenuMouseClick(sf::RenderWindow& window, 
                                          OpeningMenu& start_menu, 
                                          LoadLevel& levelManager)
{
    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if (!m_startMenuState) //still in start menu
    {
        //get the button char based on the click
        char clickedButton = start_menu.getClickedButton(mousePosition);

        switch (clickedButton)
        {
        case 'N': //new game
        {
            m_startMenuState = true;
            m_infoBar.startTimer();
            break;
        }
        case 'H': //help
        {
            start_menu.CreateHelpWindow(window);
            break;
        }
        case 'E': //exit
        {
            window.close();
            break;
        }
        default: //no button clicked
            break;
        }
    }
    else //take care other clicks in the game
    {
        return;
    }
}


//-----------------------------------------------------------------------------
void Controller::handleKeyPressed(sf::Keyboard::Key key,
                                  const sf::Time deltaTime, 
                                  GameManager& manager)
{
    manager.updateRobot(key, deltaTime);
}


//-----------------------------------------------------------------------------
void Controller::setMenuState(bool state)
{
    m_startMenuState = state;
}