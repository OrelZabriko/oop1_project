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
//void FrozenGuard::draw(sf::RenderWindow& window)
//{
//    if (!isGiftTaken())
//    {
//        window.draw(getSprite());
//    }
//}


//-----------------------------------------------------------------------------
void FrozenGuard::handleCollision(Robot& robot)
{
    giftWasTaken();
}
