//-----include section-----
#include "AddTime.h"

#include <SFML/Graphics.hpp>


//-----functions section------
//-----------------------------------------------------------------------------
AddTime::AddTime(char objType, sf::Vector2f objPlace)
    : Gifts(objType, objPlace)
{
    SetTexture(ResourceManager::getInstance().getObjectTexture(OBJECT::AddTimeGIFT));
}


//-----------------------------------------------------------------------------
//void AddTime::draw(sf::RenderWindow& window)
//{
//    if (!isGiftTaken())
//    {
//        window.draw(getSprite());
//    }
//}


//-----------------------------------------------------------------------------
void AddTime::handleCollision(Robot& robot)
{
    //logic robot ate the time gift; // bool in the robot for the time.
    giftWasTaken();
}