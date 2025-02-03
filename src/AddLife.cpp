//-----include section-----
#include "AddLife.h"

#include <SFML/Graphics.hpp>


//-----functions section------
//-----------------------------------------------------------------------------
AddLife::AddLife(char objType, sf::Vector2f objPlace)
    : Gifts(objType, objPlace)
{
    SetTexture(ResourceManager::getInstance().getObjectTexture(OBJECT::AddLifeGift));
}


//-----------------------------------------------------------------------------
//void AddLife::draw(sf::RenderWindow& window)
//{
//    if (!isGiftTaken())
//    {
//        window.draw(getSprite());
//    }
//}


//-----------------------------------------------------------------------------
void AddLife::handleCollision(Robot& robot)
{
    giftWasTaken();
}
