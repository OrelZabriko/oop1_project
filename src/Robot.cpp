//-----include section-----
#include "Robot.h"


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
void Robot::setLifeGift(bool val)
{
	m_isLifeGift = val;
}


//-----------------------------------------------------------------------------
void Robot::setTimeGift(bool val)
{
	m_isTimeGift = val;
}


//-----------------------------------------------------------------------------
bool Robot::getLifeGift() const
{
	return m_isLifeGift;
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
bool Robot::getTimeGift() const
{
	return m_isTimeGift;
}


//-----------------------------------------------------------------------------
void Robot::handleCollision(Objects& otherObject)
{
	otherObject.handleCollision(*this);
}


//-----------------------------------------------------------------------------
void Robot::handleCollision(Guard& guard)
{
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
void Robot::handleCollision(HideGuard& gift)
{
	this->setHideGift(false);
	gift.giftWasTaken();
}


//-----------------------------------------------------------------------------
void Robot::handleCollision(FrozenGuard& gift)
{
	this->setFreezeGift(true);
	gift.giftWasTaken();
}


//-----------------------------------------------------------------------------
void Robot::handleCollision(AddLife& gift)
{
	this->setLifeGift(true);
	gift.giftWasTaken();
}


//-----------------------------------------------------------------------------
void Robot::handleCollision(AddTime& gift)
{
	this->setTimeGift(true);
	gift.giftWasTaken();
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
void Robot::handleRobotDeath()
{
	ResourceManager::getInstance().playLoseMusic();

	this->decLives();
	this->setSpritePos(this->getDefPos());
}
