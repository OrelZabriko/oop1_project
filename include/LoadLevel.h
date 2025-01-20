#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Constants.h"
#include "Board.h"
#include "Level.h"
class LoadLevel
{
public:
    LoadLevel();
    const Level& getLevel()
    {
        
        if (m_currLevel > m_levels.size())
        {
            //winner?
        }
        return m_levels[m_currLevel++];
    }


private:
    int m_currLevel;
    bool readAllLevels();
        std::vector<Level> m_levels;
};

