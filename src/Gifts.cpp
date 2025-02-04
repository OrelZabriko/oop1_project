//-----include section-----
#include "Gifts.h"
#include <SFML/Graphics.hpp>


//-----functions section------
//-----------------------------------------------------------------------------
Gifts::Gifts(char objType, sf::Vector2f objPlace)
    : StaticObjects(objType, objPlace)
{}


//-----------------------------------------------------------------------------
void Gifts::draw(sf::RenderWindow& window)
{
    window.draw(getSprite());
}


//-----------------------------------------------------------------------------
void Gifts::handleCollision(Objects& otherObject)
{
    otherObject.handleCollision(*this);
}


//-----------------------------------------------------------------------------
bool Gifts::isGiftTaken()
{
    return m_isGiftNotTaken;
}


//-----------------------------------------------------------------------------
void Gifts::giftWasTaken()
{
    m_isGiftNotTaken = false;
}