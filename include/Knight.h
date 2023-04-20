#pragma once
#include "Piece.h"
#include "macros.h"

class Knight : public Piece {

public:
	Knight(bool isWhite);
	bool isAcceptableMove(const Position& source, const Position& dest) const override;
	Players getPlayer() const override;

private:


};