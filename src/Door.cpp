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

	ResourceManager::getInstance().GetBackgroundMusic().setLoop(false);
	ResourceManager::getInstance().GetBackgroundMusic().stop();

	ResourceManager::getInstance().GetWinLevelSound().play();

	robot.restartLivesNum();
	LoadLevel::setNextLevel(true);
}


//-----------------------------------------------------------------------------
void Door::handleCollision(Guard& guard)
{
	guard.setSpritePos(guard.getPrevPosition());
}