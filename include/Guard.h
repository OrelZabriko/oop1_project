#pragma once

//-----include section-----
#include "UpdatedObjects.h"
#include "ResourceManager.h"
#include "Constants.h"
#include "Robot.h"
#include "Guard.h"
#include "Rock.h"
#include "Bombs.h"

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

	void SetGuardDead(const bool& ifAlive);
	const bool& GetIfGuardAlive() const;
	
	virtual void handleCollision(Objects& otherObject) override;
	virtual void handleCollision(Robot& robot) override;
	virtual void handleCollision(Guard& guard) override;
	virtual void handleCollision(Wall& wall) override;
	virtual void handleCollision(Rock& rock) override;
	virtual void handleCollision(Door& door) override;
	virtual void handleCollision(Bombs& bomb) override;
	//virtual void handleCollision(Gift& gift) override;


private:
	sf::Vector2f m_moveDirection;
	bool m_isAlive = true;

	void moveGuardCollideWallGuard();
};