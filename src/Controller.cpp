//-----include section-----
#include "Controller.h"

#include <iostream>


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
    std::cout << " creating the manager " << std::endl;
    GameManager manager(levelManager.getLevel());
    std::cout << "finished creating the manager " << std::endl;
    sf::Clock clock;
    

    m_GameWindow.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), OPENING_WINDOW_NAME);
    m_GameWindow.setFramerateLimit(60);

    while (m_GameWindow.isOpen())
    {
        
        const auto deltaTime = clock.restart();

        if (!m_startMenuState)
        {
            start_menu.Draw(m_GameWindow);
        }
        else
        {
            m_GameWindow.clear();
            manager.draw(m_GameWindow);
        }

        //m_infoBar.draw()      

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
                handleKeyPressed(m_GameWindow, event, deltaTime, manager);
            }
            }
        }
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
            break;
        }
        case 'H': //help
        {
            window.close();
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
void Controller::handleKeyPressed(sf::RenderWindow& window, sf::Event event, const sf::Time delta,
    const GameManager& manager)
{
    std::cout << "inside handle key pressed"<< std::endl;
    switch (event.key.code)
    {
    case sf::Keyboard::Up:
        std::cout << "pressed up" << std::endl;
        //manager.getBoard().updatePlayer(UP,delta);
            break;
    
    default:
        break;
    }
}
