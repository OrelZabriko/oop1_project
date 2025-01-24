#pragma once

//-----include section-----
#include "Constants.h"
#include "ResourceManager.h"

#include <SFML/Graphics.hpp>


//-----class section-----
class Objects
{
public:
	Objects(char objType, sf::Vector2f objPlace);
	virtual ~Objects() = default;

	virtual void SetTexture() = 0;

	//virtual void SetPosition();
	virtual sf::Vector2f GetPosition() const = 0;


private:
	sf::Sprite m_objSprite;
	sf::Vector2f m_objPlace;
	//sf::Vector2f m_objectPos;
};