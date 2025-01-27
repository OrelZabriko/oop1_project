#pragma once

//-----include section-----
#include "StaticObjects.h"
#include "ResourceManager.h"
#include "Constants.h"

#include <SFML/Graphics.hpp>


//-----class section-----
class Wall : public StaticObjects
{
public:
	using StaticObjects::StaticObjects;
	virtual ~Wall() = default;
	void draw(sf::RenderWindow& window);


private:

};