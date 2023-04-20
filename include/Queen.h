#pragma once
#include "Piece.h"
#include "macros.h"
#include <iostream>

class Queen : public Piece {

public:
	Queen(bool isWhite);
	bool isAcceptableMove(const Position& source, const Position& dest) const override;
	Players getPlayer() const override;

private:


};