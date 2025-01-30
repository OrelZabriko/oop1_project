#pragma once

//-----include section-----
#include "StaticObjects.h"
#include "ResourceManager.h"
#include "Constants.h"

#include <SFML/Graphics.hpp>


//-----class section-----
class Rock : public StaticObjects
{
public:
	using StaticObjects::StaticObjects;
	virtual ~Rock() = default;
	
	virtual void handleCollision(Objects& otherObject) override;
	virtual void handleCollision(Robot& robot) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Guard& guard) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Wall& wall) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Rock& rock) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Door& door) override { /* impossible collision, ignore */ };
	//virtual void handleCollision(Bomb& bomb) override;
	//virtual void handleCollision(Gift& gift) override;


private:

};