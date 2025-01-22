#pragma once

//-----include section-----
#include "Constants.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>


//-----class section-----
class ResourceManager
{
public:
    // Deleted copy constructor and assignment operator to ensure singleton
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    // Get the singleton instance
    static ResourceManager& getInstance() {
        static ResourceManager instance;
        return instance;
    };


    // Get a texture by name
    const sf::Texture& getObjectTexture(enum OBJECT object) const;
    const sf::Texture& getStartMenuBackground();


private:
    // Private constructor for singleton
    ResourceManager();

    // Storage for textures
    std::vector<std::string> m_objNames =
    { "Door.png", "Wall.png", "Rock.png", "Robot.png", "Guard.png", "Bomb.png" };
    std::string m_StartBackGroundFileName = "StartMenuBackground.png";
    std::vector<sf::Texture> m_objects;
    std::vector<sf::Texture> m_utility;
    sf::Texture m_backGroundImage;
};