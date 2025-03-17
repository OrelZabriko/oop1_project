//-----include section-----
#include "LoadLevel.h"

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>


//-----functions section------
//-----------------------------------------------------------------------------
//Defines the static members of the LoadLevel
int LoadLevel::m_currLevel = 0;
bool LoadLevel::m_nextLevel = false;
int LoadLevel::m_addTime = 0;
int LoadLevel::m_gameTime = TIME_LIMIT;


//-----------------------------------------------------------------------------
LoadLevel::LoadLevel()
{}


//-----------------------------------------------------------------------------
bool LoadLevel::readAllLevels()
{
	std::ifstream file(LEVELS_FILE);
	if (!file.is_open())
	{
		std::cerr << "Could not open level file: " << std::endl;
		return false;
	}
	

	std::string line;
	int row = 0;
	while (std::getline(file, line))
	{
		//std::cout << "The level I read is: " << line << std::endl;

		std::ifstream level(line);
		if (!level.is_open())
		{
			std::cerr << "Could not open level file: "  << std::endl;
			return false;
		}

		std::string temp;
		Level currLevel;
		int rows, cols;
		level >> cols >> rows;
		level.get();
		currLevel.setLevelRows(rows);
		currLevel.setLevelCols(cols);
	
		while (std::getline(level, temp))
		{
			currLevel.setCell(temp);
		}
		
		m_levels.push_back(currLevel);
		level.close();
	}

	file.close();
	return true;
}


//-----------------------------------------------------------------------------
const Level& LoadLevel::getLevel()
{
	if (m_currLevel > m_levels.size())
	{
		ResourceManager::getInstance().playWinMusic();
	}
	return m_levels[m_currLevel++];
}


//-----------------------------------------------------------------------------
void LoadLevel::setNextLevel(bool val)
{
	m_nextLevel = val;
}


//-----------------------------------------------------------------------------
bool LoadLevel::getIsNextLevel()
{
	return m_nextLevel;
}


//-----------------------------------------------------------------------------
const int& LoadLevel::getCurrLevel()
{
	return m_currLevel;
}


//-----------------------------------------------------------------------------
int LoadLevel::getCurrentLevelRows() const
{
	if (m_levels.empty())
	{
		return 0;
	}
	else return m_levels[m_currLevel].getRows();
}


//-----------------------------------------------------------------------------
int LoadLevel::getCurrentLevelCols() const
{
	if (m_levels.empty())
	{
		return 0;
	}
	else return m_levels[m_currLevel].getCols();
}


//-----------------------------------------------------------------------------
void LoadLevel::restartGameTime()
{
	m_gameTime = TIME_LIMIT;
}


//-----------------------------------------------------------------------------
void LoadLevel::startTimer()
{
	m_addTime = 0;
	m_gameTimer.restart();
	m_timerStarted = true;
}


//-----------------------------------------------------------------------------
void LoadLevel::updateTime()
{
	if (m_timerStarted)
	{
		m_gameTime = TIME_LIMIT + m_addTime - static_cast<int>(m_gameTimer.getElapsedTime().asSeconds());
		if (m_gameTime < 0)
		{
			m_gameTime = 0;
			createLoseWindow();
		}
	}
}


//-----------------------------------------------------------------------------
int LoadLevel::getLevelTime()
{
	return m_gameTime;
}


//-----------------------------------------------------------------------------
void LoadLevel::addLevelTime()
{
	m_addTime += TIME_ADD;
}


//-----------------------------------------------------------------------------
bool LoadLevel::finishAllLevels()
{
	return m_currLevel == m_levels.size();
}


//-----------------------------------------------------------------------------
void LoadLevel::resetAddTime()
{
	m_addTime = 0;
}


//-----------------------------------------------------------------------------
void LoadLevel::createFinishGame()
{
	sf::RenderWindow finishWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), END_GAME_WINDOW_NAME);

	const sf::Texture& EndGameTexture = ResourceManager::getInstance().getFinishGameBackground();
	sf::Sprite EndGameBackground(EndGameTexture);

	float scaleX = static_cast<float>(WINDOW_WIDTH) / EndGameBackground.getTexture()->getSize().x;
	float scaleY = static_cast<float>(WINDOW_HEIGHT) / EndGameBackground.getTexture()->getSize().y;
	EndGameBackground.setScale(scaleX, scaleY);

	while (finishWindow.isOpen())
	{
		sf::Event event;
		while (finishWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				finishWindow.close();
			}
		}
		finishWindow.clear();
		finishWindow.draw(EndGameBackground);
		finishWindow.display();
	}
}


//-----------------------------------------------------------------------------
void LoadLevel::createLoseWindow()
{
	sf::RenderWindow loseWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), LOSE_GAME_WINDOW_NAME);

	const sf::Texture& LoseGameTexture = ResourceManager::getInstance().getLoseBackground();
	sf::Sprite LoseGameBackground(LoseGameTexture);
	float scaleX = static_cast<float>(WINDOW_WIDTH) / LoseGameBackground.getTexture()->getSize().x;
	float scaleY = static_cast<float>(WINDOW_HEIGHT) / LoseGameBackground.getTexture()->getSize().y;
	LoseGameBackground.setScale(scaleX, scaleY);

	while (loseWindow.isOpen())
	{
		sf::Event event;
		while (loseWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				loseWindow.close();
			}
		}
		loseWindow.clear();
		loseWindow.draw(LoseGameBackground);
		loseWindow.display();
	}
}