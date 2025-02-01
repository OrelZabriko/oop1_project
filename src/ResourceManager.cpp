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
		std::cerr << "Error: couldn't load the background music file\n";
	}


	if (!m_loseLevelSound.openFromFile(LOSE_LEVEL_SOUND))
	{
		std::cerr << "Error: couldn't load the background music file\n";
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