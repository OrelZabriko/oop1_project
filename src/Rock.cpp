//-----include section-----
#include "Rock.h"


//-----functions section------
//-----------------------------------------------------------------------------
void Rock::handleCollision(Objects& otherObject)
{
	otherObject.handleCollision(*this);
}

//-----------------------------------------------------------------------------
void Rock::handleCollision(Robot& robot)
{
	robot.setSpritePos(robot.getPrevPosition());
}


//-----------------------------------------------------------------------------
void Rock::handleCollision(Guard& guard)
{
    guard.setSpritePos(guard.getPrevPosition());
}