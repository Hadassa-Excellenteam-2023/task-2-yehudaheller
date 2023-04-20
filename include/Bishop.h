#pragma once
#include "Piece.h"
#include "macros.h"

class Bishop : public Piece {

public:
	Bishop(bool isWhite);
	bool isAcceptableMove(const Position& source, const Position& dest) const override;
	Players getPlayer() const override;

private:
	

};