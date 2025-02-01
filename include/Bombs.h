#pragma once

//-----include section-----
#include "UpdatedObjects.h"
#include "ResourceManager.h"
#include "Constants.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

//-----class section-----
class Bombs : public UpdatedObjects
{
public:
	Bombs(sf::Vector2f position);
	void setBomb(sf::Vector2f position);
	bool isBombActive() const;
	bool isBombExploding() const;
	void updateBomb(sf::Time deltaTime);
	void draw(sf::RenderWindow& window);
	//std::vector<sf::Vector2f> getBombPosition() const;


	virtual void handleCollision(Objects& otherObject) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Robot& robot) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Guard& guard) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Wall& wall) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Rock& rock) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Door& door) override { /* impossible collision, ignore */ };
	//virtual void handleCollision(Bombs& bomb) override { /* impossible collision, ignore */ };

private:
	sf::Time bomb_timer;
	sf::Time explosion_timer;
	bool is_bomb_active;
	bool is_bomb_exploding;
	std::vector<sf::Vector2f> activeBombs;
	void ExplodeBomb();
};



