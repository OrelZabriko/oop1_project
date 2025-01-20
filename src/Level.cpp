//-----include section-----
#include <SFML/Graphics.hpp>
#include "constants.h"
#include <iostream>
#include "Level.h"


//-----functions section------
//-----------------------------------------------------------------------------
Level::Level() : m_currentLevel(1)
{
    initializeTextures();
}

//-----------------------------------------------------------------------------
const int Level::getNumOfLevel() const
{
    return m_currentLevel;
}

//-----------------------------------------------------------------------------
bool Level::loadLevel(int levelnumber)
{
    m_currentLevel = levelnumber;
    return m_levelLoader.loadGameLevel(levelnumber);
}

//-----------------------------------------------------------------------------
void Level::initializeTextures()
{
    // Load textures for different objects
    const char* textureFiles[OBJECT_COUNT] =
    {
        "Door.png",
        "Guard.png",
        "Rock.png",
        "Robot.png",
        "Wall.png"
    };

    for (int obj = 0; obj < OBJECT_COUNT; obj++)
    {
        if (!m_textures[obj].loadFromFile(textureFiles[obj]))
        {
            std::cerr << "Failed to load texture: " << textureFiles[obj] << std::endl;
        }
        m_sprites[obj].setTexture(m_textures[obj]);
    }
}

////-----------------------------------------------------------------------------
//void Level::draw(sf::RenderWindow& window) const 
//{
//    const auto& board = m_levelLoader.getBoard();
//
//    for (int row = 0; row < m_levelLoader.getRows(); row++)
//    {
//        for (int col = 0; col < m_levelLoader.getCols(); col++) 
//        {
//            OBJECT object = getObjByChar(board[row][col]);
//
//            sf::Sprite sprite = m_sprites[object];
//            sprite.setPosition(col * TILE_SIZE, row * TILE_SIZE);
//            window.draw(sprite);
//        }
//    }
//}

