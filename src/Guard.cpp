//-----include section-----
#include "Guard.h"
#include "Controller.h"

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
{
    this->setSpritePos(getPrevPosition());
}


//-----------------------------------------------------------------------------
void Guard::handleCollision(Wall& wall)
{
    this->setSpritePos(getPrevPosition());


    //If the guard collide Wall it will change the direction and keep move (?)
    
    //this->setSpritePos(getPrevPosition());
    //// Change direction
    //sf::Vector2f currentDirection = getDirection();
    //if (currentDirection.x != 0) {
    //    // If moving horizontally, change to vertical direction
    //    m_moveDirection = sf::Vector2f(0, (currentDirection.x > 0) ? 1 : -1);
    //}
    //else {
    //    // If moving vertically, change to horizontal direction
    //    m_moveDirection = sf::Vector2f((currentDirection.y > 0) ? 1 : -1, 0);
    //}
    //// Move again
    //sf::Vector2f moveGuardOffset = getDirection() * PIXELS_FOR_MOVE_GUARD * deltaTime.asSeconds();
    //getSprite().move(moveGuardOffset);
}


//-----------------------------------------------------------------------------
void Guard::handleCollision(Rock& rock)
{
    this->setSpritePos(getPrevPosition());


    //If the guard collide Rock it will change the direction and keep move (?)
    
    //this->setSpritePos(getPrevPosition());
    //// Change direction
    //sf::Vector2f currentDirection = getDirection();
    //if (currentDirection.x != 0) {
    //    // If moving horizontally, change to vertical direction
    //    m_moveDirection = sf::Vector2f(0, (currentDirection.x > 0) ? 1 : -1);
    //}
    //else {
    //    // If moving vertically, change to horizontal direction
    //    m_moveDirection = sf::Vector2f((currentDirection.y > 0) ? 1 : -1, 0);
    //}
    //// Move again
    //sf::Vector2f moveGuardOffset = getDirection() * PIXELS_FOR_MOVE_GUARD * deltaTime.asSeconds();
    //getSprite().move(moveGuardOffset);
}
