//-----include section-----
#include "Robot.h"
#include <iostream>


//-----functions section------
//-----------------------------------------------------------------------------
//Defines the static members of the robot.
int Robot::m_livesNum = ROBOT_LIVES;
int Robot::m_currScore = RESTART_ROBOT_SCORE;


//-----------------------------------------------------------------------------
void Robot::changeDirection(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Left:
		m_moveDirection = sf::Vector2f(-1, 0);
		break;
	case sf::Keyboard::Key::Down:
		m_moveDirection = sf::Vector2f(0, 1);
		break;
	case sf::Keyboard::Key::Right:
		m_moveDirection = sf::Vector2f(1, 0);
		break;
	case sf::Keyboard::Key::Up:
		m_moveDirection = sf::Vector2f(0, -1);
		break;
	default:
		m_moveDirection = sf::Vector2f(0, 0);
		break;
	}
}


//-----------------------------------------------------------------------------
void Robot::updateSpritePos(sf::Vector2f newPos)
{
	this->setSpritePos(newPos);
}


//-----------------------------------------------------------------------------
const sf::Vector2f& Robot::getDirection() const
{
	return m_moveDirection;
}


//-----------------------------------------------------------------------------
void Robot::Move(const sf::Keyboard::Key key, const sf::Time& deltaTime)
{
	setPrevPosition(GetPosition());
	changeDirection(key);
	sf::Vector2f moveOffset = getDirection() * PIXELS_FOR_MOVE_ROBOT * deltaTime.asSeconds();
	getSprite().move(moveOffset);
}


//-----------------------------------------------------------------------------
void Robot::SetWinStat(const bool winStat)
{
	m_win = winStat;
}


//-----------------------------------------------------------------------------
const bool Robot::GetWinStat() const
{
	return m_win;
}


//-----------------------------------------------------------------------------
void Robot::setHideGift(bool val)
{
	m_isHideGuardGift = val;
}


//-----------------------------------------------------------------------------
void Robot::setFreezeGift(bool val)
{
	m_isFrozenGift = val;
}


//-----------------------------------------------------------------------------
bool Robot::getHideGift() const
{
	return m_isHideGuardGift;
}


//-----------------------------------------------------------------------------
bool Robot::getFreezeGift() const
{
	return m_isFrozenGift;
}


//-----------------------------------------------------------------------------
void Robot::incLives()
{
	m_livesNum++;
}


//-----------------------------------------------------------------------------
void Robot::decLives()
{
	m_livesNum--;
}


//-----------------------------------------------------------------------------
void Robot::restartLivesNum()
{
	m_livesNum = ROBOT_LIVES;
}


//-----------------------------------------------------------------------------
const int Robot::getLivesNum()
{
	return m_livesNum;
}


//-----------------------------------------------------------------------------
void Robot::incScore(const int morePoints)
{
	m_currScore += morePoints;
}


//-----------------------------------------------------------------------------
void Robot::decScore(const int lessPoints)
{
	m_currScore -= lessPoints;
}


//-----------------------------------------------------------------------------
void Robot::restartRobotScore()
{
	m_currScore = RESTART_ROBOT_SCORE;
}


//-----------------------------------------------------------------------------
const int Robot::getCurrScore()
{
	return m_currScore;
}


//-----------------------------------------------------------------------------
void Robot::setNeedToDecLives(bool ifDecLife)
{
	m_needToDecLives = ifDecLife;
}


//-----------------------------------------------------------------------------
const bool Robot::getNeedToDecLife() const
{
	return m_needToDecLives;
}


//-----------------------------------------------------------------------------
void Robot::handleCollision(Objects& otherObject)
{
	otherObject.handleCollision(*this);
}


//-----------------------------------------------------------------------------
void Robot::handleCollision(Robot& robot)
{}


//-----------------------------------------------------------------------------
void Robot::handleCollision(Guard& guard)
{
	/*this->decLives();
	this->setSpritePos(this->getDefPos());*/

	handleRobotDeath();
}


//-----------------------------------------------------------------------------
void Robot::handleCollision(Wall& wall)
{
	this->setSpritePos(getPrevPosition());
}


//-----------------------------------------------------------------------------
void Robot::handleCollision(Rock& rock)
{
	this->setSpritePos(getPrevPosition());
}


//-----------------------------------------------------------------------------
void Robot::handleCollision(Door& door)
{
	this->setSpritePos(getPrevPosition());

	ResourceManager::getInstance().GetBackgroundMusic().setLoop(false);
	ResourceManager::getInstance().GetBackgroundMusic().stop();

	ResourceManager::getInstance().GetWinLevelSound().play();

	this->restartLivesNum();
	LoadLevel::setNextLevel(true);
}


//-----------------------------------------------------------------------------
void Robot::handleCollision(Bombs& bomb)
{
	/*-------------------------*/
}


//-----------------------------------------------------------------------------
void Robot::handleCollision(HideGuard& gift)
{
	this->setHideGift(false);
	gift.giftWasTaken();
	std::cout << "touched a hide gift" << std::endl;
}


//-----------------------------------------------------------------------------
void Robot::handleRobotDeath()
{
	this->decLives();
	this->setSpritePos(this->getDefPos());
}
