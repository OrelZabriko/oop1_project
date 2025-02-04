//-----include section-----
#include "StaticObjects.h"


//-----functions section------
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
