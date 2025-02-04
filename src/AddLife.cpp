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
void AddLife::handleCollision(Robot& robot)
{
    robot.setLifeGift(true);
    giftWasTaken();
}