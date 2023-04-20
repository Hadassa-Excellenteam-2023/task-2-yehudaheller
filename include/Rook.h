#pragma once
#include "Piece.h"
#include "macros.h"

class Rook : public Piece {

public:
	Rook(bool isWhite);
	bool isAcceptableMove(const Position& source, const Position& dest) const override;
	Players getPlayer() const override;

private:


};