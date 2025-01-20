//-----include section-----
#include "OpeningMenu.h"

#include <vector>
#include <memory>


//-----functions section------
//-----------------------------------------------------------------------------
OpeningMenu::OpeningMenu()
{
    for (int buttons = 0; buttons < START_WINDOW_BUTTONS_NUM; buttons++)
    {
        m_menuButtons.push_back(std::make_unique<Button>(START_MENU_INDENTIFIER[buttons]));
    }

    //load the PNG file
    if (!m_backgroundImageTexture.loadFromFile("StartMenuBackground.png"))
    {
        //error handling if the image fails to load
        exit(EXIT_FAILURE);
    }

    //create a sprite and set its texture
    m_backgroundImage = sf::Sprite(m_backgroundImageTexture);
    SetScaleBackgroundImag(m_backgroundImageTexture);

    /*TextureManager backgroundImage;
    m_backgroundImage = backgroundImage.getStartMenuBackground();
    SetScaleBackgroundImag(m_backgroundImageTexture);*/
}


//-----------------------------------------------------------------------------
void OpeningMenu::SetScaleBackgroundImag(const sf::Texture& texture)
{
    //Scale the background to fit the window if needed
    float scaleX = 1920.0f / texture.getSize().x;
    float scaleY = 1080.0f / texture.getSize().y;
    m_backgroundImage.setScale(scaleX, scaleY);
}


//-----------------------------------------------------------------------------
void OpeningMenu::Draw(sf::RenderWindow& window)
{
    //draw the background
    window.draw(m_backgroundImage);

    //loop that draw the buttons.
    for (int buttonNum = 0; buttonNum < START_WINDOW_BUTTONS_NUM; buttonNum++)
    {
        m_menuButtons[buttonNum]->setPosition(buttonNum);
        m_menuButtons[buttonNum]->draw(window, START_MENU_INDENTIFIER[buttonNum]);
    }
}


//-----------------------------------------------------------------------------
//void OpeningMenu::RunStartWindow()
//{
//	//create the window. 
//	m_startMenu.create(sf::VideoMode(OPENINIG_MENU_WIDTH, OPENINIG_MENU_HEIGHT),
//					   OPENING_WINDOW_NAME);
//}








// Main game loop
//while (window.isOpen()) {
//    sf::Event event;
//    while (window.pollEvent(event)) {
//        // Close window if requested
//        if (event.type == sf::Event::Closed)
//            window.close();
//    }
//
//    // Clear the window
//    window.clear();
//
//    // Draw the background
//    window.draw(background);
//
//    // Display everything that was drawn
//    window.display();
//}
