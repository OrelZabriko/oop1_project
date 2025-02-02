//-----include section-----
#include "Objects.h"

#include <iostream>


//-----functions section------
//-----------------------------------------------------------------------------
Objects::Objects(char objType, sf::Vector2f objPlace) //: m_objPlace(objPlace)
{ 
	m_objSprite.setTexture(ResourceManager::getInstance().getObjectTexture(getObjByChar(objType)));
	m_objSprite.setPosition(objPlace.x * 55.f + 7.5f, objPlace.y * 55.f + INFOBAR_SPACE);
}


//-----------------------------------------------------------------------------
void Objects::draw(sf::RenderWindow& window)
{
	window.draw(m_objSprite);
}


//-----------------------------------------------------------------------------
void Objects::SetTexture(const sf::Texture& texture)
{
	m_objSprite.setTexture(texture);
}


//-----------------------------------------------------------------------------
//sf::Vector2f Objects::GetPosition() const
//{
//	return m_objPlace;
//}


//-----------------------------------------------------------------------------
sf::Sprite& Objects::getSprite()
{
	return m_objSprite;
}


//-----------------------------------------------------------------------------
bool Objects::collideWithOthers(const Objects& object)
{
	return m_objSprite.getGlobalBounds().intersects(object.m_objSprite.getGlobalBounds());
}


//-----------------------------------------------------------------------------
//const sf::Vector2f& Objects::getPos() const
//{
//	return m_objPlace;
//}


//-----------------------------------------------------------------------------
void Objects::setSpritePos(sf::Vector2f newPos)
{
	m_objSprite.setPosition(newPos);
}


//-----------------------------------------------------------------------------
const sf::Vector2f& Objects::GetPosition() const
{
	return m_objSprite.getPosition();
}
