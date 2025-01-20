//-----include section-----
#include "Audio.h"

#include <iostream>


//-----functions section------
//-----------------------------------------------------------------------------
//In the Audio constructor I will load all the music files.
Audio::Audio()
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
const sf::Music& Audio::GetBackgroundMusic() const
{
	return m_backgroundMusic;
}


//-----------------------------------------------------------------------------
const sf::Music& Audio::GetWinLevelSound() const
{
	return m_winLevelSound;
}


//-----------------------------------------------------------------------------
const sf::Music& Audio::GetLoseLevelSound() const
{
	return m_loseLevelSound;
}