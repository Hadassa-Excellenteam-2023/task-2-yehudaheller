#pragma once


struct Direction {
	int x;
	int y;
};


struct Position {
	int x;
	int y;

	bool operator==(const Position& other) const {
		return x == other.x && y == other.y;
	}

	bool operator!=(const Position& other) const {
		return x != other.x || y != other.y; 
	}

	Position operator+(const Position& other) const {
		return { x + other.x, y + other.y };
	}

	Position& operator+=(const Position& other) {
		*this = *this + other;
		return *this;
	}

	Position operator+(const Direction& dir) const {
		return { x + dir.x, y + dir.y };
	}

	Position& operator+=(const Direction& dir) {
		*this = *this + dir;
		return *this;
	}

};

enum Players {
	PAWN,
	KNIGHT,
	ROOK,
	KING,
	QUEEN,
	BISHOP,
};

const int ROWS = 8,
		  COLS = 8;

const Position DEFULT_POSTION = { -1,-1 };