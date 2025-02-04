//-----include section-----
#include "HideGuard.h"

#include <SFML/Graphics.hpp>
#include <iostream>


//-----functions section------
//-----------------------------------------------------------------------------
HideGuard::HideGuard(char objType, sf::Vector2f objPlace)
    : Gifts(objType, objPlace)
{
	SetTexture(ResourceManager::getInstance().getObjectTexture(OBJECT::HideGuardGift));
}


//-----------------------------------------------------------------------------
void HideGuard::handleCollision(Robot& robot)
{
	robot.setHideGift(true);
	this->giftWasTaken();  //automatically turn the bool into false;
}