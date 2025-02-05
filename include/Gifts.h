#pragma once

//-----include section-----
#include <SFML/Graphics.hpp>
#include "StaticObjects.h"
#include "constants.h"
#include "ResourceManager.h"


//-----class section-----
class Gifts : public StaticObjects
{
public:
	using StaticObjects::StaticObjects;
	virtual ~Gifts() = default;
	Gifts(char objType, sf::Vector2f objPlace);
	void draw(sf::RenderWindow& window);


	virtual void handleCollision(Objects& otherObject) override;
	virtual void handleCollision(Guard& guard) override {};
	virtual void handleCollision(Bombs& bomb) {};
	virtual void handleCollision(HideGuard& gift) override {};
	virtual void handleCollision(FrozenGuard& gift) override {};
	virtual void handleCollision(AddLife& gift) override {};
	virtual void handleCollision(AddTime& gift) override {};

	bool isGiftTaken();
	void giftWasTaken();


private:
	bool m_isGiftNotTaken = true;
};