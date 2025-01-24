#pragma once

//-----include section-----
#include "Constants.h"

#include <SFML/Graphics.hpp>


//-----class section-----
class Level
{
public:
    Level() = default;
    
    void setLevelRows(const int);
    void setLevelCols(const int);
    const int getRows() const;
    const int getCols() const;
    const std::vector<std::string>& getMatrix();
    void setCell(const std::string line);
    const char& GetObjChar(int row, int col) const;


private:
    int m_rows;
    int m_cols;
    std::vector<std::string> m_matrix;
};
