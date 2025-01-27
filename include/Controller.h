#pragma once

//-----include section-----
#include "OpeningMenu.h"
#include "GameManager.h"
#include "Objects.h"
#include "Board.h"
#include "LoadLevel.h"
#include "Level.h"

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

	void handleOpenMenuMouseClick(sf::RenderWindow& window,
		OpeningMenu& start_menu,
		LoadLevel& levelManager);
	void handleKeyPressed(sf::RenderWindow& window,
		sf::Event event, const sf::Time delta,GameManager manager);

private:
	sf::RenderWindow m_GameWindow;
	bool m_startMenuState = false;   //false == start menu //true == game started
	
	Level m_currLevel;

	void handleClicks(sf::Event event);
};