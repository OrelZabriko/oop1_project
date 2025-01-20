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
	for (int index = 0; index < m_objNames.size(); index++)
	{
		sf::Texture newTexture;
		newTexture.loadFromFile(m_objNames[index]);
		m_objects.push_back(newTexture);
	}
  
  
	m_backGroundImage.loadFromFile(m_StartBackGroundFileName);
}


//-----------------------------------------------------------------------------
const sf::Texture& TextureManager::getStartMenuBackground()
{
	return m_backGroundImage;
}


//-----------------------------------------------------------------------------
const sf::Texture& TextureManager::getTexture(enum Object object)
{
	return m_objects[object];
}
