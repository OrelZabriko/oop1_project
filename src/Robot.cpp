//-----include section-----
#include "Robot.h"


//-----functions section------
//-----------------------------------------------------------------------------
//Defines the static member of the robot that hold it's number of lives.
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
	this->decLives();
	/* need to do more things (?) */
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
