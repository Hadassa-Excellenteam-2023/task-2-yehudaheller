#include "..\include\Rook.h"

Rook::Rook(bool isWhite) : Piece(isWhite)
{
}

bool Rook::isAcceptableMove(const Position& source, const Position& dest) const
{
    return source.x == dest.x || source.y == dest.y;
}

Players Rook::getPlayer() const
{ 
    return Players::ROOK;
}
 