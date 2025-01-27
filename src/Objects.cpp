//-----include section-----
#include "Objects.h"


//-----functions section------
//-----------------------------------------------------------------------------
Objects::Objects(char objType, sf::Vector2f objPlace) : m_objPlace(objPlace)
{
	//sf::Texture new_tex = 
	m_objSprite.setTexture(ResourceManager::getInstance().getObjectTexture(getObjByChar(objType)));
	m_objSprite.setPosition(m_objPlace.x * 45.f, m_objPlace.y * 45.f);
	
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
sf::Vector2f Objects::GetPosition() const
{
	return m_objPlace;
}


//-----------------------------------------------------------------------------
sf::Sprite Objects::getSprite()
{
	return m_objSprite;
}


//-----------------------------------------------------------------------------