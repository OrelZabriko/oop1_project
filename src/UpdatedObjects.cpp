//-----include section-----
#include "UpdatedObjects.h"


//-----functions section------
//-----------------------------------------------------------------------------
void UpdatedObjects::updateSpritePos(sf::Vector2f offset)
{
	getSprite().move(offset);
}