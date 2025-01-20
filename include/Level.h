#pragma once

//-----include section-----
#include <SFML/Graphics.hpp>

#include "Constants.h"


//-----class section-----
class Level
{
public:
    Level();
    
    void setRows(const int);
    void setCols(const int);
    const int getRows() const;
    const int getCols() const;
    const std::vector<std::string>& getMatrix();
    void setCell(const std::string line);

private:
    int m_rows;
    int m_cols;
    std::vector<std::string> m_matrix;
    
};

