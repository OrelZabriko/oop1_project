#pragma once

//-----include section-----
#include "Button.h"
#include "Constants.h"
#include "TextureManager.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <memory>
#include <vector>


//-----class section-----
class OpeningMenu
{
public:
	OpeningMenu();

	//void RunStartWindow();

	void Draw(sf::RenderWindow& window);

private:
	//sf::RenderWindow m_startMenu;

	sf::Sprite m_backgroundImage;
	sf::Vector2f m_backgroundImageSize;
	std::vector<std::unique_ptr<Button>> m_menuButtons;

	void SetScaleBackgroundImag();
};