#pragma once
#include "macros.h"

class Piece {

public:
	Piece(bool isWhite);
	virtual ~Piece() = default;
	virtual bool isAcceptableMove(const Position & source, const Position & dest) const = 0;
	virtual Players getPlayer() const = 0;
	bool getPieceColor() const;
	
private:
	Position m_position;
	bool m_color;

};
