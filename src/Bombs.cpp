//-----include section-----
#include "Bombs.h"

#include <SFML/Graphics.hpp>


//-----functions section------
//-----------------------------------------------------------------------------
Bombs::Bombs(sf::Vector2f position)
    : m_bomb_timer(sf::seconds(EXPLOSION_TIME)),
      m_is_bomb_active(false),
      m_is_bomb_exploding(false)
{
    getSprite().setTexture(ResourceManager::getInstance().getBombTexture());
    getSprite().setScale(0.5f, 0.5f);
    setSpritePos(position);
}


//-----------------------------------------------------------------------------
void Bombs::setBomb(sf::Vector2f position, sf::Vector2f robotOrigin)
{
    if (!m_is_bomb_active && !m_is_bomb_exploding)
    {
        setSpritePos(position);
        this->getSprite().setOrigin(robotOrigin);
        m_is_bomb_active = true;
        m_bomb_timer = sf::seconds(EXPLOSION_TIME);
    }
}


//-----------------------------------------------------------------------------
void Bombs::updateBomb(sf::Time deltaTime)
{
    if (m_is_bomb_active)
    {
        m_bomb_timer -= deltaTime;
        if (m_bomb_timer.asSeconds() <= 0)
        {
            m_is_bomb_active = false;
            m_is_bomb_exploding = true;
            this->ExplodeBomb();
        }
    }
    else if (m_is_bomb_exploding)
    {
        m_explosion_timer -= deltaTime;
        if (m_explosion_timer.asSeconds() <= 0)
        {
            m_is_bomb_exploding = false;
            m_activeBombs.clear();
        }
    }
}


//-----------------------------------------------------------------------------
void Bombs::draw(sf::RenderWindow& window)
{
    if (m_is_bomb_active)
    {
        sf::Sprite& bombSprite = getSprite();
        bombSprite.setPosition(getSprite().getPosition());
        window.draw(bombSprite);
    }

    if (m_is_bomb_exploding)
    {
        sf::Sprite explosionSprite(ResourceManager::getInstance().getExplosionTexture());
        explosionSprite.setScale(0.15f, 0.15f);
        for (int bombsNum = 0; bombsNum < m_activeBombs.size(); bombsNum++)
        {
            explosionSprite.setPosition(m_activeBombs[bombsNum]);
            window.draw(explosionSprite);
        }
    }
}


//-----------------------------------------------------------------------------
void Bombs::handleCollision(Objects& otherObject)
{
    otherObject.handleCollision(*this);
}


//-----------------------------------------------------------------------------
void Bombs::handleCollision(Robot& robot)
{}


//-----------------------------------------------------------------------------
void Bombs::handleCollision(Guard& guard)
{
    guard.SetGuardDead(true);
}


//-----------------------------------------------------------------------------
void Bombs::handleCollision(Rock & rock)
{
    rock.setToDisappear(true);
}


//-----------------------------------------------------------------------------
void Bombs::ExplodeBomb()
{
    m_activeBombs.clear();
    sf::Vector2f center = getSprite().getPosition();
    m_activeBombs.push_back(center);

    for (int direction = 0; direction < 4; direction++)
    {
        sf::Vector2f explosionPos = center;

        switch (direction)
        {
        case 0: //right
            explosionPos.x += EXPLOSION_RANGE;
            break;
        case 1: //left
            explosionPos.x -= EXPLOSION_RANGE;
            break;
        case 2: //down
            explosionPos.y += EXPLOSION_RANGE;
            break;
        case 3: //up
            explosionPos.y -= EXPLOSION_RANGE;
            break;
        }

        m_activeBombs.push_back(explosionPos);
    }
    m_is_bomb_exploding = true;
    m_explosion_timer = sf::seconds(LATENCY_EXPOLDE_TIME);
}


//-----------------------------------------------------------------------------
bool Bombs::isBombActive() const
{
    return m_is_bomb_active;
}


//-----------------------------------------------------------------------------
bool Bombs::isBombExploding() const
{
    return m_is_bomb_exploding;
}