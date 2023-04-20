#include "..\include\Pawn.h"

Pawn::Pawn(bool isWhite): Piece(isWhite)
{
}

bool Pawn::isAcceptableMove(const Position& source, const Position& dest) const
{
    if (m_thisIsFirstMove)
        if (this->getPieceColor())
            return (dest.x == source.x + 2 || dest.x == source.x + 1) && dest.y == source.y;
        else
            return (dest.x == source.x - 2 || dest.x == source.x - 1) && dest.y == source.y;
    else
        if (this->getPieceColor())
            return dest.x == source.x + 1 && dest.y == source.y;
        else
            return dest.x == source.x - 1 && dest.y == source.y;
}

void Pawn::setFirstMove()
{
    m_thisIsFirstMove = false;
}

Players Pawn::getPlayer() const
{
    return Players::PAWN;
}
