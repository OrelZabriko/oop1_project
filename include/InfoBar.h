#pragma once

//-----include section-----
#include "Robot.h"
#include "LoadLevel.h"

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
    void setTime(int time);
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

    int m_time = 180;
};