#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Constants.h"
#include "Board.h"

class LoadLevel
{
public:
    LoadLevel() = default;
    bool loadGameLevel(int levelNumber);


private:
    bool readLevelFromFile(const std::string& levelname);
    BOARD m_board;  
};

