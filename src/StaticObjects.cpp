//-----include section-----
#include "StaticObjects.h"


//-----functions section------
//-----------------------------------------------------------------------------
void StaticObjects::handleCollision(Wall& wall)
{}


//-----------------------------------------------------------------------------
void StaticObjects::handleCollision(Rock& rock)
{}


//-----------------------------------------------------------------------------
void StaticObjects::handleCollision(Door& door)
{}


//-----------------------------------------------------------------------------
void StaticObjects::setToDisappear(bool ifDisappear)
{
	m_needToDisappear = ifDisappear;
}


//-----------------------------------------------------------------------------
const bool StaticObjects::getNeedToDisappear() const
{
	return m_needToDisappear;
}
