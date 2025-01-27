#pragma once

//-----include section-----
#include "Objects.h"


//-----class section-----
class UpdatedObjects : public Objects
{
public:
	using Objects::Objects;
	virtual ~UpdatedObjects() = default;

	//virtual sf::Vector2f updateMovment(ENUM DIRECTIONS,DELATTIME);
	void updateSpritePos(sf::Vector2f offset);
		
	
private:

};
