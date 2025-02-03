#pragma once

//-----include section-----
#include "StaticObjects.h"
#include "ResourceManager.h"
#include "Constants.h"
#include "Robot.h"
#include "Guard.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


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
	virtual void handleCollision(HideGuard& gift) override {};
	virtual void handleCollision(Bombs& bomb) override { /* impossible collision, ignore */ };
	//virtual void handleCollision(Gift& gift) override;
};