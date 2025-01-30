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
LoadLevel::LoadLevel()
{
	readAllLevels();
}


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
		std::ifstream level(line);
		if (!file.is_open())
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
		//winner?

		ResourceManager::getInstance().GetWinLevelSound().play();
		std::this_thread::sleep_for(std::chrono::seconds(5)); 
		ResourceManager::getInstance().GetWinLevelSound().stop();
	}
	return m_levels[m_currLevel++];
}


//-----------------------------------------------------------------------------
int LoadLevel::getCurrentLevelRows() const
{
	if (m_levels.empty())
	{
		return 0;
	}
	else return m_levels[0].getRows();
}


//-----------------------------------------------------------------------------
int LoadLevel::getCurrentLevelCols() const
{
	if (m_levels.empty())
	{
		return 0;
	}
	else return m_levels[0].getCols();
}