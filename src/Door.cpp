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
{}


//-----------------------------------------------------------------------------
void Door::handleCollision(Guard& guard)
{}
