#pragma once

//-----include section-----
#include <SFML/Graphics.hpp>


//-----class section-----
class Objects
{
public:
	Objects(sf::Texture objTexture, sf::Vector2i objPlace);
	virtual ~Objects() = default;

	virtual void SetTexture() = 0;

	virtual sf::Vector2f GetPosition() const = 0;

protected:
	sf::Sprite m_objSprite;
	sf::Vector2i m_objPlace;
	//sf::Vector2f m_objectPos;
};