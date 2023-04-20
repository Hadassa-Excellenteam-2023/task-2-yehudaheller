#include "..\include\Queen.h"


Queen::Queen(bool isWhite) : Piece(isWhite)
{
}

bool Queen::isAcceptableMove(const Position& source, const Position& dest) const
{
    return (source.x == dest.x || source.y == dest.y) || (std::abs(dest.x - source.x) == std::abs(dest.y - source.y));
}

Players Queen::getPlayer() const
{
    return Players::QUEEN;
}


