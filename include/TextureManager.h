#pragma once

//-----include section-----
#include "Constants.h"

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <memory>


//-----class section-----
class TextureManager
{
public:
    // Deleted copy constructor and assignment operator to ensure singleton
    TextureManager(const TextureManager&) = delete;
    TextureManager& operator=(const TextureManager&) = delete;

    // Get the singleton instance
    static TextureManager& getInstance() {
        static TextureManager instance;
        return instance;
    };


    // Get a texture by name
    const sf::Texture& getTexture(enum Object object);
    const sf::Texture& getStartMenuBackground();



private:
    // Private constructor for singleton
    TextureManager();

    // Storage for textures
    std::vector<std::string> m_objNames =
    { "Door.png", "Wall.png", "Rock.png", "Robot.png", "Guard.png", "Bomb.png" };
    std::string m_StartBackGroundFileName = "StartMenuBackground.png";
    std::vector<sf::Texture> m_objects;
    std::vector<sf::Texture> m_utility;
    sf::Texture m_backGroundImage;
};