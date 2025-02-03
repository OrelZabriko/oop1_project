#pragma once

//-----include section-----
#include "UpdatedObjects.h"
#include "ResourceManager.h"
#include "Constants.h"
#include "LoadLevel.h"
#include "Robot.h"
#include "Guard.h"
#include "Rock.h"
#include "Bombs.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


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

	void setHideGift(bool val);
	void setFreezeGift(bool val);

	bool getHideGift() const;
	bool getFreezeGift() const;

	static void incLives();
	static void decLives();
	static void restartLivesNum();
	static const int getLivesNum();

	static void incScore(const int morePoints);
	static void decScore(const int lessPoints);
	static void restartRobotScore();
	static const int getCurrScore();
	
	virtual void handleCollision(Objects& otherObject) override;
	virtual void handleCollision(Robot& robot) override;
	virtual void handleCollision(Guard& guard) override;
	virtual void handleCollision(Wall& wall) override;
	virtual void handleCollision(Rock& rock) override;
	virtual void handleCollision(Door& door) override;
	virtual void handleCollision(Bombs& bomb) override { /* impossible collision, ignore */ };
	virtual void handleCollision(HideGuard& gift) override;


private:
	sf::Vector2f m_moveDirection;
	bool m_win = false; //Boolean variable check if the robot win the level
	bool m_isFrozenGift = false;
	bool m_isHideGuardGift = false;
	static int m_livesNum;
	static int m_currScore;
};