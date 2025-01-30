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
void Guard::handleCollision(Objects& otherObject)
{
    otherObject.handleCollision(*this);
}
