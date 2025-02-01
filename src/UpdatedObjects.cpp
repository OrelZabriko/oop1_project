//-----include section-----
#include "UpdatedObjects.h"
#include <iostream>

//-----functions section------
//----------------------------------------------------------------------------- 
UpdatedObjects::UpdatedObjects() //: m_startPos(this->GetPosition())
{}


//-----------------------------------------------------------------------------
void UpdatedObjects::Move(sf::Vector2f offset)
{
	getSprite().move(offset);
}


void UpdatedObjects::setSpritePos(sf::Vector2f newPos)
{
	m_previousPos = GetPosition();
	Base::setSpritePos(newPos);
}


//-----------------------------------------------------------------------------
void UpdatedObjects::setStartPos(const sf::Vector2f& startPos)
{
	m_startPos = startPos;
}


//-----------------------------------------------------------------------------
sf::Vector2f UpdatedObjects::getStartPosition() const
{
	return m_startPos;
}


//-----------------------------------------------------------------------------
void UpdatedObjects::setPrevPosition(sf::Vector2f position)
{
	m_previousPos = position;
}


//-----------------------------------------------------------------------------
sf::Vector2f UpdatedObjects::getPrevPosition() const
{
	return m_previousPos;
}