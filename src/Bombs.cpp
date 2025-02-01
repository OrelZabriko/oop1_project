
//-----include section-----
#include "Bombs.h"
#include <SFML/Graphics.hpp>
#include <iostream>


//-----functions section------
//-----------------------------------------------------------------------------

Bombs::Bombs(sf::Vector2f position)
    : bomb_timer(sf::seconds(EXPLOSION_TIME))
    , is_bomb_active(false)
    , is_bomb_exploding(false)
{
    getSprite().setTexture(ResourceManager::getInstance().getBombTexture());
    getSprite().setScale(0.5f, 0.5f);  
    setSpritePos(position);

}

//-----------------------------------------------------------------------------
void Bombs::setBomb(sf::Vector2f position)
{
    if (!is_bomb_active && !is_bomb_exploding)
    {
        setSpritePos(position);
        is_bomb_active = true;
        bomb_timer = sf::seconds(EXPLOSION_TIME);
    }
}

//-----------------------------------------------------------------------------
void Bombs::updateBomb(sf::Time deltaTime)
{
    if (is_bomb_active)
    {
        bomb_timer -= deltaTime;
        if (bomb_timer.asSeconds() <= 0)
        {
            is_bomb_active = false;
            is_bomb_exploding = true;
            ExplodeBomb();
        }
    }
    else if (is_bomb_exploding) 
    {
        explosion_timer -= deltaTime;
        if (explosion_timer.asSeconds() <= 0)
        {
            is_bomb_exploding = false;
            activeBombs.clear();
        }
    }
}

//-----------------------------------------------------------------------------
void Bombs::draw(sf::RenderWindow& window)
{ 
    if (is_bomb_active)
    {
        sf::Sprite& bombSprite = getSprite();
        bombSprite.setPosition(getSprite().getPosition()); 
        window.draw(bombSprite);
    }

    if (is_bomb_exploding)
    {
        sf::Sprite explosionSprite(ResourceManager::getInstance().getExplosionTexture());
        explosionSprite.setScale(0.15f, 0.15f);
        for (int bombsNum = 0; bombsNum < activeBombs.size(); bombsNum++)
        {
            explosionSprite.setPosition(activeBombs[bombsNum]);
            window.draw(explosionSprite);
        }
    }
}

//-----------------------------------------------------------------------------
void Bombs::ExplodeBomb()
{
    activeBombs.clear();
    sf::Vector2f center = getSprite().getPosition();
    activeBombs.push_back(center);

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
        case 3: //down
            explosionPos.y -= EXPLOSION_RANGE;
            break;
        }

        activeBombs.push_back(explosionPos);
    }
    is_bomb_exploding = true;
    explosion_timer = sf::seconds(0.3f);
}

//-----------------------------------------------------------------------------
bool Bombs::isBombActive() const
{
    return is_bomb_active;
}

//-----------------------------------------------------------------------------
bool Bombs::isBombExploding() const
{
    return is_bomb_exploding;
}

//-----------------------------------------------------------------------------
//std::vector<sf::Vector2f> Bombs::getBombPosition() const
//{
//    return Bomb_position;
//}
