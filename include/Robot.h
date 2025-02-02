#pragma once

//-----include section-----
#include "UpdatedObjects.h"
#include "ResourceManager.h"
#include "Constants.h"
class Rock;

#include <SFML/Graphics.hpp>


//-----class section-----
class Robot : public UpdatedObjects
{
public:
	using UpdatedObjects::UpdatedObjects;
	virtual ~Robot() = default;

	void changeDirection(sf::Keyboard::Key key);
	void updateSpritePos(sf::Vector2f newPos);

	const sf::Vector2f& getDirection() const;

	void Move(const sf::Keyboard::Key key, const sf::Time& deltaTime);

	void SetWinStat(const bool winStat);
	const bool GetWinStat() const;

	static void incLives();
	static void decLives();
	static const int& getLivesNum();
	
	virtual void handleCollision(Objects& otherObject) override;
	virtual void handleCollision(Robot& robot) override;
	virtual void handleCollision(Guard& guard) override;
	virtual void handleCollision(Wall& wall) override;
	virtual void handleCollision(Rock& rock) override;
	virtual void handleCollision(Door& door) override { /* impossible collision, ignore */ };
	//virtual void handleCollision(Bomb& bomb) override;
	//virtual void handleCollision(Gift& gift) override;


private:
	sf::Vector2f m_moveDirection;
	bool m_win = false; //Boolean variable check if the robot win the level
	static int m_livesNum;
};