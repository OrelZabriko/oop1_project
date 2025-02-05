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
    static ResourceManager& getInstance();


    const sf::Texture& getObjectTexture(enum OBJECT object) const; //Get a texture by name
    const sf::Texture& getStartMenuBackground();
    const sf::Texture& getHelpStartMenuBackground();
    const sf::Texture& getBombTexture();
    const sf::Texture& getExplosionTexture();
    const sf::Texture& getFinishGameBackground();
    const sf::Texture& getLoseBackground();

    sf::Music& GetBackgroundMusic();
    sf::Music& GetWinLevelSound();
    sf::Music& GetLoseLevelSound();

    const sf::Font& GetTextFont() const;

    const sf::Time& getDeltaTime() const;
    void setDeltaTime(const sf::Time& newDeltaTime);

    void playBackgroundMusic();
    void playWinMusic();
    void playLoseMusic();


private:
    ResourceManager(); //Private constructor for singleton
    void loadTextures();
    void loadMusic();
    void loadTextFont();


    //Storage for textures
    std::vector<std::string> m_objNames =
    { "Door.png", "Wall.png", "Rock.png", "Robot.png", "Guard.png" , "Clock.png" , "Life.png" , "Frozen.png" , "HideGuard.png" };
    std::string m_StartBackGroundFileName = "StartMenuBackground.png";
    std::string m_HelpBackGroundFileName = "Help.png";
    std::string m_BombFileName = "Bomb.png";
    std::string m_ExplosionBombFileName = "Explosion.png";
    std::string m_EndGameFileName = "WIN.png";
    std::string m_LoseFileName = "LOSE.png";
    std::vector<sf::Texture> m_objects;
    std::vector<sf::Texture> m_utility;
    sf::Texture m_backGroundImage;
    sf::Texture m_HelpBackGroundImage;
    sf::Texture m_BombTexture;
    sf::Texture m_ExplosionTexture;
    sf::Texture m_EndGameImage;
    sf::Texture m_LoseGameImage;

    //Storage for music
    sf::Music m_backgroundMusic;
    sf::Music m_winLevelSound;
    sf::Music m_loseLevelSound;

    //Storage for font
    sf::Font m_txtFont;

    //Storage the Delta time of the game
    sf::Time m_deltaTime;
};