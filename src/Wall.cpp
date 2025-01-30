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
//void Wall::RobotCollide(Robot& robot)
//{
//	//robot.setPosition(robot.getPrevLocation());
//	robot.setPrevPosition(robot.getPrevPosition());
//}
