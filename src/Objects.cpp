//-----include section-----
#include "Objects.h"


//-----functions section------
//-----------------------------------------------------------------------------
Objects::Objects(char objType, sf::Vector2f objPlace) : m_objPlace(objPlace)
{
	sf::Texture new_tex = ResourceManager::getInstance().getObjectTexture(getObjByChar(objType));
	m_objSprite.setTexture(new_tex);
	m_objSprite.setOrigin(static_cast<float>(m_objSprite.getTexture()->getSize().x) / 2.0f, 
						  static_cast<float>(m_objSprite.getTexture()->getSize().y) / 2.0f);
}