#pragma once

//-----include section-----
#include "Constants.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
    static ResourceManager& getInstance() ;


    // Get a texture by name
    const sf::Texture& getObjectTexture(enum OBJECT object) const;
    const sf::Texture& getStartMenuBackground();
    const sf::Texture& getHelpStartMenuBackground();
    const sf::Texture& getBombTexture();
    const sf::Texture& getExplosionTexture();

    sf::Music& GetBackgroundMusic();
    sf::Music& GetWinLevelSound();
    sf::Music& GetLoseLevelSound();

    const sf::Font& GetTextFont() const;


private:
    //Private constructor for singleton
    ResourceManager();
    void loadTextures();
    void loadMusic();
    void loadTextFont();

    //Storage for textures
    std::vector<std::string> m_objNames =
    { "Door.png", "Wall.png", "Rock.png", "Robot.png", "Guard.png" };
    std::string m_StartBackGroundFileName = "StartMenuBackground.png";
    std::string m_HelpBackGroundFileName = "Help.png";
    std::string m_BombFileName = "Bomb.png";
    std::string m_ExplosionBombFileName = "Explosion.png";
    std::vector<sf::Texture> m_objects;
    std::vector<sf::Texture> m_utility;
    sf::Texture m_backGroundImage;
    sf::Texture m_HelpBackGroundImage;
    sf::Texture m_BombTexture;
    sf::Texture m_ExplosionTexture;

    //Storage for music
    sf::Music m_backgroundMusic;
    sf::Music m_winLevelSound;
    sf::Music m_loseLevelSound;

    //Storage for font
    sf::Font m_txtFont;
};