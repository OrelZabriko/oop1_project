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

    static void setNextLevel(bool val);

    bool getIsNextLevel();

    
    static const int& getCurrLevel();

    int getCurrentLevelRows() const;
    int getCurrentLevelCols() const;


private:
    static int m_currLevel;
    static bool m_nextLevel;
    std::vector<Level> m_levels;
};

