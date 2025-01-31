//-----include section-----
#include "Robot.h"


//-----functions section------
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
}


//-----------------------------------------------------------------------------
void Robot::handleCollision(Wall& wall)
{
	this->setSpritePos(getPrevPosition());
}
