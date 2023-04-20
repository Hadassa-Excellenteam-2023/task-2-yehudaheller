#include "..\include\Piece.h"

Piece::Piece(bool isWhite)
{
	m_color = isWhite;
	
}


bool Piece::getPieceColor() const
{
	return m_color;
}

