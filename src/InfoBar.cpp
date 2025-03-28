//-----include section-----
#include "InfoBar.h"
#include "Button.h"
#include "ResourceManager.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>


//-----functions section------
//-----------------------------------------------------------------------------
InfoBar::InfoBar()
{
    m_font = ResourceManager::getInstance().GetTextFont();
}


//-----------------------------------------------------------------------------
void InfoBar::drawInfoBar(sf::RenderWindow& window)
{
    //initialize the lives
    m_livesText.setFont(m_font);
    m_livesText.setCharacterSize(INFOBAR_FONT_CHARACTERS_SIZE);
    m_livesText.setFillColor(sf::Color::White);
    m_livesText.setString("Lives: " + std::to_string(Robot::getLivesNum()));

    //initialize the time
    m_timeText.setFont(m_font);
    m_timeText.setCharacterSize(INFOBAR_FONT_CHARACTERS_SIZE);
    m_timeText.setFillColor(sf::Color::White);
    m_timeText.setString("Time: " + std::to_string(LoadLevel::getLevelTime()));

    //initialize the level number
    m_levelText.setFont(m_font);
    m_levelText.setCharacterSize(INFOBAR_FONT_CHARACTERS_SIZE);
    m_levelText.setFillColor(sf::Color::White);
    m_levelText.setString("Level: " + std::to_string(LoadLevel::getCurrLevel()));

    //initialize the player score
    m_scoreText.setFont(m_font);
    m_scoreText.setCharacterSize(INFOBAR_FONT_CHARACTERS_SIZE);
    m_scoreText.setFillColor(sf::Color::White);
    m_scoreText.setString("Score: " + std::to_string(Robot::getCurrScore()));


    float x_position = 10.f;
    float y_Position = 10.f;

    m_livesText.setPosition(x_position, y_Position);
    m_timeText.setPosition(m_livesText.getPosition().x + m_livesText.getLocalBounds().width + 3 * x_position, y_Position);
    m_levelText.setPosition(m_timeText.getPosition().x + m_timeText.getLocalBounds().width + 3 * x_position, y_Position);
    m_scoreText.setPosition(m_levelText.getPosition().x + m_levelText.getLocalBounds().width + 3 * x_position, y_Position);

    window.draw(m_livesText);
    window.draw(m_timeText);
    window.draw(m_levelText);
    window.draw(m_scoreText);
}