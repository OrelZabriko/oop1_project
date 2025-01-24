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
}


//-----------------------------------------------------------------------------
void ResourceManager::loadMusic()
{
	if (!m_backgroundMusic.openFromFile(BOMBERMAN_CAKGROUND_SOUND))
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
const sf::Texture& ResourceManager::getObjectTexture(enum OBJECT object) const
{
	return m_objects[object];
}


//-----------------------------------------------------------------------------
const sf::Music& ResourceManager::GetBackgroundMusic() const
{
	return m_backgroundMusic;
}


//-----------------------------------------------------------------------------
const sf::Music& ResourceManager::GetWinLevelSound() const
{
	return m_winLevelSound;
}


//-----------------------------------------------------------------------------
const sf::Music& ResourceManager::GetLoseLevelSound() const
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