//-----include section-----
#include "ResourceManager.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <string>
#include <vector>


//-----functions section------
//-----------------------------------------------------------------------------
ResourceManager& ResourceManager::getInstance()
{
	static ResourceManager instance;
	return instance;
}


//-----------------------------------------------------------------------------
ResourceManager::ResourceManager()
{
	loadTextures();
	loadMusic();
	loadTextFont();
}


//-----------------------------------------------------------------------------
void ResourceManager::loadTextures()
{
	for (int index = 0; index < m_objNames.size(); index++)
	{
		sf::Texture newTexture;
		newTexture.loadFromFile(m_objNames[index]);
		m_objects.push_back(newTexture);
	}


	m_backGroundImage.loadFromFile(m_StartBackGroundFileName);

	m_HelpBackGroundImage.loadFromFile(m_HelpBackGroundFileName);

	m_BombTexture.loadFromFile(m_BombFileName);

	m_ExplosionTexture.loadFromFile(m_ExplosionBombFileName);

	m_EndGameImage.loadFromFile(m_EndGameFileName);

	m_LoseGameImage.loadFromFile(m_LoseFileName);
}


//-----------------------------------------------------------------------------
void ResourceManager::loadMusic()
{
	if (!m_backgroundMusic.openFromFile(BOMBERMAN_BACKGROUND_SOUND))
	{
		std::cerr << "Error: couldn't load the background music file\n";
	}


	if (!m_winLevelSound.openFromFile(WIN_LEVEL_SOUND))
	{
		std::cerr << "Error: couldn't load the win sound file\n";
	}


	if (!m_loseLevelSound.openFromFile(LOSE_LEVEL_SOUND))
	{
		std::cerr << "Error: couldn't load the lose sound file\n";
	}


	if (!m_gameOverSound.openFromFile(GAME_OVER_SOUND))
	{
		std::cerr << "Error: couldn't load the game-over sound file\n";
	}


	if (!m_explosionSound.openFromFile(EXPLOSION_SOUND))
	{
		std::cerr << "Error: couldn't load the explosion sound file\n";
	}
}


//-----------------------------------------------------------------------------
const sf::Texture& ResourceManager::getStartMenuBackground()
{
	return m_backGroundImage;
}


//-----------------------------------------------------------------------------
const sf::Texture& ResourceManager::getHelpStartMenuBackground()
{
	return m_HelpBackGroundImage;
}


//-----------------------------------------------------------------------------
const sf::Texture& ResourceManager::getBombTexture()
{
	return m_BombTexture;
}


//-----------------------------------------------------------------------------
const sf::Texture& ResourceManager::getExplosionTexture()
{
	return m_ExplosionTexture;
}


//-----------------------------------------------------------------------------
const sf::Texture& ResourceManager::getObjectTexture(enum OBJECT object) const
{
	return m_objects[object];
}


//-----------------------------------------------------------------------------
const sf::Texture& ResourceManager::getFinishGameBackground()
{
	return m_EndGameImage;
}


//-----------------------------------------------------------------------------
const sf::Texture& ResourceManager::getLoseBackground()
{
	return m_LoseGameImage;
}


//-----------------------------------------------------------------------------
sf::Music& ResourceManager::GetBackgroundMusic()
{
	return m_backgroundMusic;
}


//-----------------------------------------------------------------------------
sf::Music& ResourceManager::GetWinLevelSound()
{
	return m_winLevelSound;
}


//-----------------------------------------------------------------------------
sf::Music& ResourceManager::GetLoseLevelSound()
{
	return m_loseLevelSound;
}


//-----------------------------------------------------------------------------
sf::Music& ResourceManager::GetGameOverSound()
{
	return m_gameOverSound;
}


//-----------------------------------------------------------------------------
sf::Music& ResourceManager::GetExplosionSound()
{
	return m_explosionSound;
}


//-----------------------------------------------------------------------------
void ResourceManager::loadTextFont()
{
	if (!m_txtFont.loadFromFile("GOUDYSTO.TTF"))
	{
		exit(EXIT_FAILURE); //Make sure you have a valid font file
	}
}


//-----------------------------------------------------------------------------
const sf::Font& ResourceManager::GetTextFont() const
{
	return m_txtFont;
}


//-----------------------------------------------------------------------------
void ResourceManager::playBackgroundMusic()
{
	m_backgroundMusic.setLoop(true);
	m_backgroundMusic.setVolume(BACKGROUND_MUSIC_REGULAR_VOLUME);
	m_backgroundMusic.play();  //Start the music
}


//-----------------------------------------------------------------------------
void ResourceManager::playWinMusic()
{
	m_backgroundMusic.setVolume(BACKGROUND_MUSIC_LOWER_VOLUME);
	m_winLevelSound.setVolume(WIN_MUSIC_REGULAR_VOLUME);
	m_winLevelSound.play();
	m_backgroundMusic.setVolume(BACKGROUND_MUSIC_LOWER_VOLUME);
}


//-----------------------------------------------------------------------------
void ResourceManager::playLoseMusic()
{
	m_backgroundMusic.setVolume(BACKGROUND_MUSIC_LOWER_VOLUME);
	m_loseLevelSound.setVolume(WIN_MUSIC_REGULAR_VOLUME);
	m_loseLevelSound.play();
	m_backgroundMusic.setVolume(BACKGROUND_MUSIC_REGULAR_VOLUME);
}


//-----------------------------------------------------------------------------
void ResourceManager::playGameOverMusic()
{
	m_gameOverSound.setVolume(GAME_OVER_REGULAR_VOLUME);
	m_backgroundMusic.stop();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	m_gameOverSound.play();
}


//-----------------------------------------------------------------------------
void ResourceManager::playExplosionMusic()
{
	m_explosionSound.setVolume(EXPLOSION_REGULAR_VOLUME);
	m_explosionSound.play();
}