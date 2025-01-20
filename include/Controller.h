#pragma once

//-----include section-----
#include "OpeningMenu.h"

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
	//handle click
	// /*
	// m_upper_menu->handleclick;
	//hanle hover
	//handleMove()
	//
	//handlers
	//update - change positionts
	//draw



private:
	sf::RenderWindow m_GameWindow;
	// Board m_board;

};