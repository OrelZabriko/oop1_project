#pragma once

//-----include section-----
#include "StaticObjects.h"
#include "ResourceManager.h"
#include "Constants.h"
#include "Robot.h"

#include <SFML/Graphics.hpp>


//-----class section-----
class Wall : public StaticObjects
{
public:
	using StaticObjects::StaticObjects;
	virtual ~Wall() = default;
	void draw(sf::RenderWindow& window);

	virtual void handleCollision(Objects& otherObject) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Robot& robot) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Guard& guard) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Wall& wall) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Rock& rock) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Door& door) override { /* impossible collision, ignore */ };
	//virtual void handleCollision(Bomb& bomb) override;
	//virtual void handleCollision(Gift& gift) override;


private:

};