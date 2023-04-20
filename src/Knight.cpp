#include "..\include\Knight.h"
#include <iostream>
#include <vector>

Knight::Knight(bool isWhite) : Piece(isWhite)
{
}

bool Knight::isAcceptableMove(const Position& source, const Position& dest) const
{
    auto row = std::abs(source.x - dest.x);
    auto col = std::abs(source.y - dest.y);

    return (row == 2 && col == 1) || (row == 1 && col == 2);
}

Players Knight::getPlayer() const
{
    return Players::KNIGHT;
}
