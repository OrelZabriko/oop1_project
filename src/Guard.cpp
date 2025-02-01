//-----include section-----
#include "Guard.h"


//-----functions section------
//-----------------------------------------------------------------------------
void Guard::setDirection(sf::Vector2f position)
{
    float xDistance = this->GetPosition().x - position.x;
    float yDistance = this->GetPosition().y - position.y;

    if (std::abs(yDistance) > std::abs(xDistance))
    {
        if (yDistance > 0)
        {
            m_moveDirection = sf::Vector2f(0, -1);//up
        }
        else
        {
            m_moveDirection = sf::Vector2f(0, 1);//down
        }
    }
    else
    {
        if (xDistance > 0)
        {
            m_moveDirection = sf::Vector2f(-1, 0); //left
        }
        else
        {
            m_moveDirection = sf::Vector2f(1, 0); //right
        }
    }
}


//-----------------------------------------------------------------------------
const sf::Vector2f& Guard::getDirection() const
{
    return m_moveDirection;
}


//-----------------------------------------------------------------------------
void Guard::Move(const sf::Time& deltaTime, const sf::Vector2f robotPos)
{
    setPrevPosition(GetPosition());
    setDirection(robotPos);
    sf::Vector2f moveGuardOffset = getDirection() * PIXELS_FOR_MOVE_GUARD * deltaTime.asSeconds();
    getSprite().move(moveGuardOffset);
}


//-----------------------------------------------------------------------------
void Guard::SetGuardDead(const bool& ifAlive)
{
    m_isAlive = ifAlive;
}


//-----------------------------------------------------------------------------
const bool& Guard::GetIfGuardAlive() const
{
    return m_isAlive;
}


//-----------------------------------------------------------------------------
void Guard::handleCollision(Objects& otherObject)
{
    otherObject.handleCollision(*this);
}


//-----------------------------------------------------------------------------
void Guard::handleCollision(Robot& robot)
{
    /*need to do something*/
}


//-----------------------------------------------------------------------------
void Guard::handleCollision(Guard& guard)
{}


//-----------------------------------------------------------------------------
void Guard::handleCollision(Wall& wall)
{
    this->setSpritePos(getPrevPosition());
}


//-----------------------------------------------------------------------------
void Guard::handleCollision(Rock& rock)
{
    this->setSpritePos(getPrevPosition());
}
