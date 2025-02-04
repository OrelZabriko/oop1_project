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
void AddTime::handleCollision(Robot& robot)
{
    robot.setTimeGift(true);
    this->giftWasTaken();
}