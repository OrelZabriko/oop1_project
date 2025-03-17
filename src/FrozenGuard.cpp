//-----include section-----
#include "FrozenGuard.h"

#include <SFML/Graphics.hpp>


//-----functions section------
//-----------------------------------------------------------------------------
FrozenGuard::FrozenGuard(char objType, sf::Vector2f objPlace)
    : Gifts(objType, objPlace)
{
    SetTexture(ResourceManager::getInstance().getObjectTexture(OBJECT::FrozenGuardGift));
}


//-----------------------------------------------------------------------------
void FrozenGuard::handleCollision(Robot& robot)
{
    robot.setFreezeGift(true);
    this->giftWasTaken();
}
