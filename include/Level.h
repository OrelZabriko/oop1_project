#pragma once

//-----include section-----
#include <SFML/Graphics.hpp>
#include "LoadLevel.h"
#include "Constants.h"


//-----class section-----
class Level
{
public:
    Level();
    const int getNumOfLevel() const;
    bool loadLevel(int levelnumber);
    void draw(sf::RenderWindow& window) const;


private:
    void initializeTextures();
    LoadLevel m_levelLoader;
    int m_currentLevel;
    sf::Texture m_textures[OBJECT_COUNT];
    sf::Sprite m_sprites[OBJECT_COUNT];
};

