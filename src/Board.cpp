//-----include section-----
#include "Button.h"


//-----functions section------
//-----------------------------------------------------------------------------
Button::Button(char buttonName) : m_buttonType(buttonName)
{
    setSize();  //Initialize size when button is created
}


//-----------------------------------------------------------------------------
sf::Vector2f Button::getPosition() const
{
    return m_position;
}


//-----------------------------------------------------------------------------
void Button::setPosition(int place)
{
    m_position.x = (BUTTON_WIDTH + BUTTON_SPACING) * place + 10.f;;
    m_position.y = 30.f;
}


//-----------------------------------------------------------------------------
sf::Vector2f Button::getSize() const
{
    return m_size;
}


//-----------------------------------------------------------------------------
void Button::setSize()
{
    m_size.x = BUTTON_WIDTH;
    m_size.y = BUTTON_HEIGHT;
}


//-----------------------------------------------------------------------------
sf::RectangleShape Button::makeButtonRectangle() const
{
    sf::RectangleShape buttonRectangle(m_size);

    buttonRectangle.setPosition(m_position);

    // Change outline color based on hover state
    if (m_isOnIt)
    {
        buttonRectangle.setOutlineColor(sf::Color::Red); //Highlight color when hovered
        buttonRectangle.setOutlineThickness(20);         //Thicker outline when hovered
    }
    else
    {
        buttonRectangle.setOutlineColor(sf::Color::Black);
        buttonRectangle.setOutlineThickness(15);
    }

    buttonRectangle.setFillColor(sf::Color(173, 216, 230));
    buttonRectangle.setTexture(NULL);

    return buttonRectangle;
}


//-----------------------------------------------------------------------------
//This function draw each button.
//void Button::draw(sf::RenderWindow& window) const
//{
//    //draw the button rectangle first
//    window.draw(makeButtonRectangle());
//
//    //draw the sprite using the button's actual position and size
//    sf::Sprite button;
//    
//    button.setTexture(texture);
//    button.setPosition(m_position);
//
//    //scale the sprite to fit the button size
//    sf::Vector2u textureSize = texture.getSize();
//    float scaleX = m_size.x / textureSize.x;
//    float scaleY = m_size.y / textureSize.y;
//    button.setScale(scaleX, scaleY);
//
//    window.draw(button);
//}


//-----------------------------------------------------------------------------
const char Button::getButtonType() const
{
    return m_buttonType;
}


//-----------------------------------------------------------------------------
void Button::setIsOnIt(bool isOnIt)
{
    m_isOnIt = isOnIt;
}


//-----------------------------------------------------------------------------
bool Button::getIsOnIt() const
{
    return m_isOnIt;
}
