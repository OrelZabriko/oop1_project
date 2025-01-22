//-----include section-----
#include "Objects.h"


//-----functions section------
//-----------------------------------------------------------------------------
Objects::Objects(sf::Texture objTexture, sf::Vector2i objPlace) :
		m_objPlace(objPlace)
{
	m_objSprite.setTexture(objTexture);
}