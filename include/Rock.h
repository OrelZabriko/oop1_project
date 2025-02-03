#pragma once

//-----include section-----
#include "StaticObjects.h"
#include "ResourceManager.h"
#include "Constants.h"
#include "Robot.h"
#include "Guard.h"
#include "Bombs.h"

#include <SFML/Graphics.hpp>


//-----class section-----
class Rock : public StaticObjects
{
public:
	using StaticObjects::StaticObjects;
	virtual ~Rock() = default;
	
	virtual void handleCollision(Objects& otherObject) override;
	virtual void handleCollision(Robot& robot) override;
	virtual void handleCollision(Guard& guard) override;
	virtual void handleCollision(Bombs& bomb) override { /* impossible collision, ignore */ };
	virtual void handleCollision(HideGuard& gift) override {};
};