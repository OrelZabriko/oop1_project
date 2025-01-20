//-----include section-----
#include "Controller.h"
#include "Audio.h"
#include "LoadLevel.h"

//-----functions section------
//-----------------------------------------------------------------------------
void Controller::run()
{
	OpeningMenu start_menu;
    LoadLevel levelManager;
    
	sf::RenderWindow window;
    //add a comment
    window.create(sf::VideoMode(OPENINIG_MENU_WIDTH, OPENINIG_MENU_HEIGHT), OPENING_WINDOW_NAME);

    while (window.isOpen())
    {
        window.clear();
        if(!m_state)
        start_menu.Draw(window);
        else {
            //m_board.draw();
            //m_infobar.draw()       }

        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
            {
                window.close();
                break;
            }
            //case clicked new game
            // m_board(levelManager.getLevel());
            // m_state = true;

            }
        }
        window.display();
    }
}


