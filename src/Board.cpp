//-----include section-----
#include "Board.h"

#include <SFML/Graphics.hpp>


//-----functions section------
//-----------------------------------------------------------------------------
//Board::Board() : m_rows(0), m_cols(0), m_board() 
//{}


//-----------------------------------------------------------------------------
//This function initialized the board and ask from the user to enter new 
//number of rows and cols.
//void Board::resetBoard(const int rows, const int cols)
//{
//	m_rows = rows;
//	m_cols = cols;
//
//	m_board.resize(m_rows);
//	for (int row = 0; row < m_rows; row++)
//	{
//		m_board[row].resize(m_cols);
//		for (int col = 0; col < m_cols; col++)
//		{
//			m_board[row][col].SetRow(m_rows);
//			m_board[row][col].SetCol(m_cols);
//			m_board[row][col].SetCellSize();
//			m_board[row][col].SetCellPos(col, row);
//		}
//	}
//}


//-----------------------------------------------------------------------------
//int Board::GetRows() const
//{
//	return m_rows;
//}
//
//
////-----------------------------------------------------------------------------
//int Board::GetCols() const
//{
//	return m_cols;
//}