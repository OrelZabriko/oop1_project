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

	ResourceManager::getInstance().GetBackgroundMusic().pause();
	ResourceManager::getInstance().GetWinLevelSound().play();
	ResourceManager::getInstance().GetWinLevelSound().stop();
	ResourceManager::getInstance().GetBackgroundMusic().play();

	robot.restartLivesNum();
	LoadLevel::setNextLevel(true);
}


//-----------------------------------------------------------------------------
void Door::handleCollision(Guard& guard)
{
	guard.setSpritePos(guard.getPrevPosition());
}