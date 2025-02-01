#pragma once

//-----include section-----
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Constants.h>

//-----class section-----
class InfoBar
{
public:
    InfoBar();
    void drawInfoBar(sf::RenderWindow& window);
    void setLives(int lives);
    void setTime(int time);
    void setLevel(int level);
    void setScore(int score);
    void updateTime();
    void startTimer();

private:
    sf::Font m_font;
    sf::Text m_livesText;
    sf::Text m_timeText;
    sf::Text m_levelText;
    sf::Text m_scoreText;
    sf::Clock m_gameTimer;
    bool m_timerStarted = false;
    int m_lives = 5;
    int m_time = 180;
    int m_level = 1;
    int m_score = 0;
};