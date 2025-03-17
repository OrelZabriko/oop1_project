#pragma once

//-----include section-----
#include "StaticObjects.h"
#include "ResourceManager.h"
#include "Constants.h"
#include "Robot.h"
#include "Guard.h"

#include <SFML/Graphics.hpp>


//-----class section-----
class Wall : public StaticObjects
{
public:
	using StaticObjects::StaticObjects;
	virtual ~Wall() = default;
	void draw(sf::RenderWindow& window);

	virtual void handleCollision(Objects& otherObject) override;
	virtual void handleCollision(Robot& robot) override;
	virtual void handleCollision(Guard& guard) override;
	virtual void handleCollision(Bombs& bomb) override {};
	virtual void handleCollision(HideGuard& gift) override {};
	virtual void handleCollision(FrozenGuard& gift) override {};
	virtual void handleCollision(AddLife& gift) override {};
	virtual void handleCollision(AddTime& gift) override {};
};