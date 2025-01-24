#pragma once

//-----include section-----
#include "Constants.h"
#include "ResourceManager.h"
#include "Button.h"
#include "Board.h"
#include "LoadLevel.h"
#include "Level.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <memory>
#include <vector>


//-----class section-----
class GameWindow
{
public:
	GameWindow() = default;
	GameWindow(const Level& currLevel);


private:
	Level m_currLevel;
	Board m_currBoard;
};