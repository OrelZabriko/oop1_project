//-----include section-----
#include "Rock.h"


//-----functions section------
//-----------------------------------------------------------------------------
void Rock::handleCollision(Objects& otherObject)
{
	otherObject.handleCollision(*this);
}
