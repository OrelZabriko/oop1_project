//-----include section-----
#include "Door.h"


//-----functions section------
//-----------------------------------------------------------------------------
void Door::handleCollision(Objects& otherObject)
{
	otherObject.handleCollision(*this);
}


//-----------------------------------------------------------------------------
void Door::handleCollision(Robot& robot)
{
	robot.setSpritePos(robot.getPrevPosition());
	robot.incScore(WIN_LEVEL_SCORE);

	ResourceManager::getInstance().playWinMusic();
	
	LoadLevel::setNextLevel(true);
	LoadLevel::restartGameTime();
}


//-----------------------------------------------------------------------------
void Door::handleCollision(Guard& guard)
{
	guard.setSpritePos(guard.getPrevPosition());
}