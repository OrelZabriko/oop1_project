#pragma once

//-----include section-----
#include "OpeningMenu.h"
#include "Board.h"
#include "Audio.h"
#include "LoadLevel.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <fstream>
#include <memory>
#include <vector>


//-----class section-----
class Controller
{
public:
	Controller() = default;

	void Run();


private:
	sf::RenderWindow m_GameWindow;
	bool m_startMenuState = false;   //false == start menu //true game started
	Board m_board;

	void handleClicks(sf::Event event);
};