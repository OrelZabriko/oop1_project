//-----include section-----
#include "Objects.h"


//-----functions section------
//-----------------------------------------------------------------------------
Objects::Objects(char objType, sf::Vector2f objPlace) : m_objPlace(objPlace)
{
	//sf::Texture new_tex = 
	m_objSprite.setTexture(ResourceManager::getInstance().getObjectTexture(getObjByChar(objType)));
	m_objSprite.setPosition(m_objPlace.x * 32, m_objPlace.y * 32);
	
}

void Objects::draw(sf::RenderWindow& window)
{
	window.draw(m_objSprite);
}
