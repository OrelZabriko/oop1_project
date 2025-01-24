#pragma once

//-----include section-----
#include "Constants.h"
#include "Board.h"
#include "Level.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>


//-----class section-----
class LoadLevel
{
public:
    LoadLevel();

    bool readAllLevels();

    const Level& getLevel();

    int getCurrentLevelRows() const;
    int getCurrentLevelCols() const;


private:
    int m_currLevel;
    std::vector<Level> m_levels;
};

