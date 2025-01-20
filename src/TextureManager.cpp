//-----include section-----
#include "TextureManager.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <string>
#include <vector>


//-----functions section------
//-----------------------------------------------------------------------------
TextureManager::TextureManager()
{
	std::vector<sf::Texture> textures;

	for (int index = 0; index < m_objNames.size(); index++)
	{
		sf::Texture newTexture;
		newTexture.loadFromFile(m_objNames[index]);
		textures.push_back(newTexture);
	}


	for (int index = 0; index < m_objNames.size(); index++)
	{
		sf::Sprite newSprite;
		newSprite.setTexture(textures[index]);
		m_objectSprites.push_back(newSprite);
	}


	sf::Texture startBackgroundTexture;
	startBackgroundTexture.loadFromFile(m_StartBackGroundFileName);
	m_StartMenuBackground.setTexture(startBackgroundTexture);
}


//-----------------------------------------------------------------------------
const sf::Sprite& TextureManager::getStartMenuBackground() const
{
	return m_StartMenuBackground;
}