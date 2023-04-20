#pragma once
#include "Piece.h"
#include "macros.h"

class King : public Piece {

public:
	King(bool isWhite);
	bool isAcceptableMove(const Position& source, const Position& dest) const override;
	Players getPlayer() const override;
private:


};