#pragma once

//-----include section-----
#include "UpdatedObjects.h"
#include "ResourceManager.h"
#include "Constants.h"

#include <SFML/Graphics.hpp>


//-----class section-----
class Guard : public UpdatedObjects
{
public:
	using UpdatedObjects::UpdatedObjects;
	virtual ~Guard() = default;

	void setDirection(sf::Vector2f position);
	const sf::Vector2f& getDirection() const;

	void Move(const sf::Time& deltaTime, const sf::Vector2f robotPos);

	virtual void handleCollision(Objects& otherObject) override;
	virtual void handleCollision(Robot& robot) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Guard& guard) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Wall& wall) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Rock& rock) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Door& door) override { /* impossible collision, ignore */ };
	//virtual void handleCollision(Bomb& bomb) override;
	//virtual void handleCollision(Gift& gift) override;


private:
	sf::Vector2f m_moveDirection;
	bool isAlive = true;
};