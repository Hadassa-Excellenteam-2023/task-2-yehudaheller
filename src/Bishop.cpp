#include "..\include\Bishop.h"
#include <iostream>

Bishop::Bishop(bool isWhite) :
    Piece(isWhite)
{
}

bool Bishop::isAcceptableMove(const Position& source, const Position& dest) const
{
    auto x = std::abs(dest.x - source.x);
    auto y = std::abs(dest.y - source.y);

    return x == y;
}

Players Bishop::getPlayer() const
{
    return Players::BISHOP;
}
