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
    initializeFont();
}

//-----------------------------------------------------------------------------
void InfoBar::setLives(int lives)
{
    m_lives = lives;
}

//-----------------------------------------------------------------------------
void InfoBar::setTime(int time)
{ 
    m_time = time; 
}

//-----------------------------------------------------------------------------
void InfoBar::setLevel(int level)
{
    m_level = level;
}

//-----------------------------------------------------------------------------
void InfoBar::setScore(int score)
{
    m_score = score; 
}

//-----------------------------------------------------------------------------
void InfoBar::initializeFont() 
{
    if (!m_font.loadFromFile("GOUDYSTO.TTF"))
    {
        exit(EXIT_FAILURE);;
    }
}


//-----------------------------------------------------------------------------
void InfoBar::startTimer() 
{
    m_gameTimer.restart();
    m_timerStarted = true;
}


//-----------------------------------------------------------------------------
void InfoBar::updateTime()
{
    if (m_timerStarted) 
    {
        int gameTime = TIME_LIMIT - static_cast<int>(m_gameTimer.getElapsedTime().asSeconds());
        if (gameTime < 0) 
        {
            gameTime = 0;
        }
        m_time = gameTime;
    }
}


//-----------------------------------------------------------------------------
void InfoBar::drawInfoBar(sf::RenderWindow& window)
{
    updateTime();
    sf::Text livesText, timeText, levelText, scoreText;
     
    //initialize the lives
    livesText.setFont(m_font);
    livesText.setCharacterSize(20);
    livesText.setFillColor(sf::Color::White);
    livesText.setString("Lives: " + std::to_string(m_lives));

    //initialize the time
    timeText.setFont(m_font);
    timeText.setCharacterSize(20);
    timeText.setFillColor(sf::Color::White);
    timeText.setString("Time: " + std::to_string(m_time));

    //initialize the level number
    levelText.setFont(m_font);
    levelText.setCharacterSize(20);
    levelText.setFillColor(sf::Color::White);
    levelText.setString("Level: " + std::to_string(m_level));

    //initialize the player score
    scoreText.setFont(m_font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setString("Score: " + std::to_string(m_score));
    
    livesText.setString("Lives: " + std::to_string(m_lives));
    timeText.setString("Time: " + std::to_string(m_time));
    levelText.setString("Level: " + std::to_string(m_level));
    scoreText.setString("Score: " + std::to_string(m_score));

    float x_position = 10.f;
    float y_Position = x_position;

    livesText.setPosition(x_position, y_Position);
    timeText.setPosition(livesText.getPosition().x + livesText.getLocalBounds().width + 3 * x_position, y_Position);
    levelText.setPosition(timeText.getPosition().x + timeText.getLocalBounds().width + 3 * x_position, y_Position);
    scoreText.setPosition(levelText.getPosition().x + levelText.getLocalBounds().width + 3 * x_position, y_Position);

    window.draw(livesText);
    window.draw(timeText);
    window.draw(levelText);
    window.draw(scoreText);
}





