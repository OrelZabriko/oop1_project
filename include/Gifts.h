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


	virtual void handleCollision(Objects& otherObject) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Robot& robot) override { /* impossible collision, ignore */ };
	virtual void handleCollision(Guard& guard) override { /* impossible collision, ignore */ };

	virtual void handleCollision(Bombs& bomb) { /* impossible collision, ignore */ };

	bool isGiftTaken();
	void giftWasTaken();


private:
	bool m_isGiftNotTaken = true;
};