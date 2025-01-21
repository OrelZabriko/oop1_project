//-----include section-----
#include "Controller.h"


//-----functions section------
//-----------------------------------------------------------------------------
void Controller::Run()
{
    OpeningMenu start_menu;
    LoadLevel levelManager;

    sf::Clock clock;
    
    m_GameWindow.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), OPENING_WINDOW_NAME);

    while (m_GameWindow.isOpen())
    {
        const auto deltaTime = clock.restart();

        m_GameWindow.clear();

        if (!m_startMenuState)
        {
            start_menu.Draw(m_GameWindow);
        }
        //m_board.draw();
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
            case sf::Event::MouseButtonReleased:
            {
                handleClicks(event);
            }
            //case clicked new game
            // m_board(levelManager.getLevel());
            // m_state = true;
            }
        }
        m_GameWindow.display();
    }
}


//-----------------------------------------------------------------------------
void Controller::handleClicks(sf::Event event)
{

}