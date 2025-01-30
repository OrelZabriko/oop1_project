#pragma once

//-----include section-----
#include "Button.h"
#include "Constants.h"
#include "ResourceManager.h"

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

	char getClickedButton(const sf::Vector2f& mousePosition) const;

	void Draw(sf::RenderWindow& window);

	void CreateHelpWindow(sf::RenderWindow& window);
	void ResetSettings();

private:
	sf::Sprite m_backgroundImage;
	sf::Sprite m_helpBackgroundImage;
	sf::Vector2f m_backgroundImageSize;
	std::vector<std::unique_ptr<Button>> m_menuButtons;
	sf::Text m_helpText;

	void SetScaleBackgroundImag();
};