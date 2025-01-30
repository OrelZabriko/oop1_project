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
	}
}


//-----------------------------------------------------------------------------
const sf::Vector2f& Robot::getDirection() const
{
	return m_moveDirection;
}


//-----------------------------------------------------------------------------
void Robot::handleCollision(Objects& otherObject)
{
	otherObject.handleCollision(*this);
}


//-----------------------------------------------------------------------------
void Robot::handleCollision(Guard& guard)
{
}


//-----------------------------------------------------------------------------
void Robot::handleCollision(Wall& wall)
{
	this->setSpritePos(getPrevPosition());
}


//-----------------------------------------------------------------------------
void Robot::updateSpritePos(sf::Vector2f newPos)
{
	this->setSpritePos(newPos);
}
