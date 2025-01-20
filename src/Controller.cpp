//-----include section-----
#include "Controller.h"
#include "Audio.h"


//-----functions section------
//-----------------------------------------------------------------------------
void Controller::Run()
{
	OpeningMenu start_menu;

	sf::RenderWindow window;

    window.create(sf::VideoMode(OPENINIG_MENU_WIDTH, OPENINIG_MENU_HEIGHT), OPENING_WINDOW_NAME);

    while (window.isOpen())
    {
        window.clear();

        start_menu.Draw(window);


        if (auto event = sf::Event{}; window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
            {
                window.close();
                break;
            }
            }
        }
        window.display();
    }
}