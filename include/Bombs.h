#pragma once

//-----include section-----
#include "UpdatedObjects.h"
#include "ResourceManager.h"
#include "Constants.h"
#include "Robot.h"
#include "Guard.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>


//-----class section-----
class Bombs : public UpdatedObjects
{
public:
	Bombs(sf::Vector2f position);
	virtual ~Bombs() = default;

	void setBomb(sf::Vector2f position);
	bool isBombActive() const;
	bool isBombExploding() const;
	void updateBomb(sf::Time deltaTime);
	void draw(sf::RenderWindow& window);
	//const std::vector<sf::Vector2f>& Bombs::getBombPosition() const;

	virtual void handleCollision(Objects& otherObject) override;
	virtual void handleCollision(Robot& robot) override;
	virtual void handleCollision(Guard& guard) override;
	virtual void handleCollision(Wall& wall) override;
	virtual void handleCollision(Rock& rock) override;
	virtual void handleCollision(Door& door) override;
	virtual void handleCollision(Bombs& bomb) override { /* impossible collision, ignore */ };


private:
	sf::Time m_bomb_timer;
	sf::Time m_explosion_timer;
	bool m_is_bomb_active;
	bool m_is_bomb_exploding;
	std::vector<sf::Vector2f> m_activeBombs;

	void ExplodeBomb();
};