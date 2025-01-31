//-----include section-----
#include "Wall.h"


//-----functions section------
//-----------------------------------------------------------------------------
void Wall::draw(sf::RenderWindow& window)
{
	window.draw(getSprite());
}


//-----------------------------------------------------------------------------
void Wall::handleCollision(Objects& otherObject)
{
	otherObject.handleCollision(*this);
}


//-----------------------------------------------------------------------------
void Wall::handleCollision(Robot& robot)
{
	robot.setSpritePos(robot.getPrevPosition());
}


//-----------------------------------------------------------------------------
void Wall::handleCollision(Guard& guard)
{
	guard.setSpritePos(guard.getPrevPosition());
}
