//-----include section-----
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <LoadLevel.h>


//-----functions section------
//-----------------------------------------------------------------------------
LoadLevel::LoadLevel()
{
	readAllLevels();
}

bool LoadLevel::readAllLevels()
{
	std::string levels_file("LevelList.txt");
	std::ifstream file(levels_file);
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

		std::cout << "read cols:" << cols << "read rows" << rows << std::endl;
		currLevel.setRows(rows);
		currLevel.setCols(cols);
	
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