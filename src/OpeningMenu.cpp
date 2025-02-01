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


//-----------------------------------------------------------------------------
//This function will return the constant char of the button that clicked.
char OpeningMenu::getClickedButton(const sf::Vector2f& mousePosition) const
{
    for (int buttons = 0; buttons < START_WINDOW_BUTTONS_NUM; buttons++)
    {
        const sf::Vector2f buttonPosition = m_menuButtons[buttons]->getPosition();
        const sf::Vector2f buttonSize = m_menuButtons[buttons]->getSize();

        if (CheckLimits(mousePosition, buttonPosition, buttonSize))
        {
            return START_MENU_INDENTIFIER[buttons];
        }
    }

    return '\0'; //no button clicked
}


//-----------------------------------------------------------------------------
void OpeningMenu::CreateHelpWindow(sf::RenderWindow& window)
{
    sf::RenderWindow helpWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Help Window");
    //load the  setting image background
    const sf::Texture& helpTexture = ResourceManager::getInstance().getHelpStartMenuBackground();

    sf::Sprite helpBackground(helpTexture);

    //do the scale
    float scaleX = WINDOW_WIDTH / helpBackground.getTexture()->getSize().x;
    float scaleY = WINDOW_HEIGHT / helpBackground.getTexture()->getSize().y;
    helpBackground.setScale(scaleX, scaleY);


    ResetSettings();      //create the settings
    createBackButton();  //create the back buttin

    while (helpWindow.isOpen())
    {
        sf::Event event;
        while (helpWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                helpWindow.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                if (mouseX >= m_backButton.getPosition().x &&
                    mouseX <= m_backButton.getPosition().x + m_backButton.getSize().x &&
                    mouseY >= m_backButton.getPosition().y &&
                    mouseY <= m_backButton.getPosition().y + m_backButton.getSize().y)
                {
                    helpWindow.close();
                }
            }
        }

        helpWindow.clear();
        helpWindow.draw(helpBackground);
        helpWindow.draw(m_helpText);
        helpWindow.draw(m_backButton);
        helpWindow.draw(m_backButtonText);
        helpWindow.display();
    }
}


//-----------------------------------------------------------------------------
void OpeningMenu::ResetSettings()
{
    m_helpText.setFont(ResourceManager::getInstance().GetTextFont());
    m_helpText.setString
    ("Bomberman game settings:\n\n"
        "- The goal: get out of the maze\n"
        "- place bombs to destroy the guards \n"
        "- You can not walk through rocks and walls\n"
        "- When you touch a guard, you lose life\n"
        "Movement:\n"
        "- Arrow Keys: Move character\n"
        "- 'b': create bomb\n"
        "Tips:\n"
        "- Use bombs to explode rocks\n"
        "- Collect gifts for bonuses");

    m_helpText.setCharacterSize(35);
    m_helpText.setFillColor(sf::Color::Red);
    m_helpText.setPosition(WINDOW_WIDTH / 8.f, WINDOW_HEIGHT / 4.5f);
}


//-----------------------------------------------------------------------------
void OpeningMenu::createBackButton()
{
    float backButtonX = WINDOW_WIDTH / 2.f - BUTTON_WIDTH / 2.f;
    float backButtonY = WINDOW_HEIGHT - 110;

    m_backButton.setSize(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_backButton.setFillColor(sf::Color::Black);
    m_backButton.setOutlineColor(sf::Color::White);
    m_backButton.setOutlineThickness(3);
    m_backButton.setPosition(backButtonX, backButtonY);

    //initialize text
    m_backButtonText.setFont(ResourceManager::getInstance().GetTextFont());
    m_backButtonText.setString("Back to Menu");
    m_backButtonText.setCharacterSize(20);
    m_backButtonText.setFillColor(sf::Color::White);

    //write inside the button
    m_backButtonText.setPosition(backButtonX + 15, backButtonY + 40);
}