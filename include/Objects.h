#pragma once

//-----include section-----
#include "Constants.h"
#include "ResourceManager.h"
class Robot;
class Guard;
class Wall;
class Rock;
class Door;
class Bombs;

#include <SFML/Graphics.hpp>


//-----class section-----
class Objects
{
public:
	Objects() = default;
	Objects(char objType, sf::Vector2f objPlace);
	virtual ~Objects() = default;

	void SetTexture(const sf::Texture& texture);

	void setSpritePos(sf::Vector2f newPos);
	const sf::Vector2f& GetPosition() const;
	sf::Vector2f getDefPos() const;
	void draw(sf::RenderWindow& window);

	sf::Sprite& getSprite();

	virtual bool collideWithOthers(const Objects& object);
	virtual void handleCollision(Objects& otherObject) = 0;
	virtual void handleCollision(Robot& robot) = 0;
	virtual void handleCollision(Guard& guard) = 0;
	virtual void handleCollision(Wall& wall) = 0;
	virtual void handleCollision(Rock& rock) = 0;
	virtual void handleCollision(Door& door) = 0;
	virtual void handleCollision(Bombs& bomb) = 0;
	//virtual void handleCollision(Gift& gift) = 0;


private:
	sf::Sprite m_objSprite;
	sf::Vector2f m_defaultPos;
	//sf::Vector2f m_objPlace;
};