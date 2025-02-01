#pragma once

//-----include section-----
#include "StaticObjects.h"
#include "ResourceManager.h"
#include "Constants.h"

#include <SFML/Graphics.hpp>


//-----class section-----
class Door : public StaticObjects
{
public:
	using StaticObjects::StaticObjects;
	virtual ~Door() = default;
	
	using StaticObjects::handleCollision;

	void handleCollision(Objects& otherObject) override;
	void handleCollision(Robot& robot) override;
	void handleCollision(Guard& guard) override;
	//virtual void handleCollision(Bomb& bomb) override;
	//virtual void handleCollision(Gift& gift) override;
};