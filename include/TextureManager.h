#pragma once

//-----include section-----
#include "Constants.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>


//-----class section-----
class TextureManager
{
public:
	TextureManager();

	//const sf::Texture& getTexture(OBJECT obj) const;
	const sf::Sprite& getStartMenuBackground() const;

private:
	std::vector<sf::Sprite> m_objectSprites;
	std::vector<std::string> m_objNames =
	{ "Door.png", "Wall.png", "Rock.png", "Robot.png",
	  "Guard.png" };
	sf::Sprite m_StartMenuBackground;
	std::string m_StartBackGroundFileName = "StartMenuBackground.png";
};