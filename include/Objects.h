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

	void SetTexture(const sf::Texture& texture)
	{
		m_objSprite.setTexture(texture);
	};

	//virtual void SetPosition();
	sf::Vector2f GetPosition() const
	{
		return m_objPlace;
	};

	void draw(sf::RenderWindow& window);

	sf::Sprite getSprite()
	{
		return m_objSprite;
	};

private:
	sf::Sprite m_objSprite;
	sf::Vector2f m_objPlace;
	//sf::Vector2f m_objectPos;
};