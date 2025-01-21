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


    //create a sprite and set its texture
    m_backgroundImage = sf::Sprite(ResourceManager::getInstance().getStartMenuBackground());

    SetScaleBackgroundImag();
}


//-----------------------------------------------------------------------------
void OpeningMenu::SetScaleBackgroundImag()
{
    //Scale the background to fit the window if needed
    float scaleX = 1920.0f / ResourceManager::getInstance().getStartMenuBackground().getSize().x;
    float scaleY = 1080.0f / ResourceManager::getInstance().getStartMenuBackground().getSize().y;
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