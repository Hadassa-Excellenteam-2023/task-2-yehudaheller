#pragma once
#include "Piece.h"
#include "macros.h"

class Pawn : public Piece {

public:
	Pawn(bool isWhite);
	bool isAcceptableMove(const Position& source, const Position& dest) const override;
	void setFirstMove();
	Players getPlayer() const override;

private:
	bool m_thisIsFirstMove = true;


};