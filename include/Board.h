#pragma once

#include "macros.h"
#include "Piece.h"
#include "Factory.h"

#include <memory>
#include <iostream>
#include <vector>


class Board {

public:
	Board(const std::string& bStr);
	int codeRespone(const std::string& move);

private:
	bool m_currentPlayerIsWhite;
	std::unique_ptr<Piece> m_board[ROWS][COLS];
	Position m_king[2];
	
	void clearAndBuildBoard(const std::string& bStr);

	bool isEmpty(const Position source) const;
	bool isRival(const Position source) const;
	bool isCurrentTurnPiece(const Position source) const;
	bool isWayBloacked(const Position& source, const Position& dest) const;
	bool isPossibleChess(const Position& source, const Position& dest);
	bool isKing(const Position& location) const;
	bool isGameOver() const;
	std::vector<Position> getOpponentMoves() const;
	void update(const Position source, const Position dest);
	bool isPawn(const Position& location) const;

};

