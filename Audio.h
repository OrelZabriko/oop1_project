#pragma once

//-----include section-----
#include "Constants.h"

#include <SFML/Audio.hpp>


//-----class section-----
class Audio
{
public:
	Audio();

	const sf::Music& GetBackGroundMusic() const;
	const sf::Music& GetWinLevelSound() const;
	const sf::Music& GetLoseLevelSound() const;

private:
	sf::Music m_backgroundMusic;
	sf::Music m_winLevelSound;
	sf::Music m_loseLevelSound;
};