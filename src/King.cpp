#include "..\include\King.h"
#include <iostream>

King::King(bool isWhite): Piece(isWhite)
{
}

bool King::isAcceptableMove(const Position& source, const Position& dest) const
{


    int row = std::abs(dest.x - source.x);
    int col = std::abs(dest.y - source.y);

    return (row == 0 && col == 0) ? false : ((row <= 1 && col <= 1) ? true : false);


}

Players King::getPlayer() const
{
    return Players::KING;
}
