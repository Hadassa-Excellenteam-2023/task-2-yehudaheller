#pragma once

#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "macros.h"

#include <functional>
#include <memory>
#include <map>


class Factory {

public:
    std::unique_ptr<Piece> buildQueen(bool isWhite) {
        return std::make_unique<Queen>(isWhite);
    }

    std::unique_ptr<Piece> buildKing(bool isWhite) {
        return std::make_unique<King>(isWhite);
    }

    std::unique_ptr<Piece> buildRook(bool isWhite) {
        return std::make_unique<Rook>(isWhite);
    }

    std::unique_ptr<Piece> buildKnight(bool isWhite) {
        return std::make_unique<Knight>(isWhite);
    }

    std::unique_ptr<Piece> buildBishop(bool isWhite) {
        return std::make_unique<Bishop>(isWhite);
    }

    std::unique_ptr<Piece> buildPawn(bool isWhite) {
        return std::make_unique<Pawn>(isWhite);
    }

    Factory() {
        m_buildPiece['Q'] = std::bind(&Factory::buildQueen, this, std::placeholders::_1);
        m_buildPiece['K'] = std::bind(&Factory::buildKing, this, std::placeholders::_1);
        m_buildPiece['R'] = std::bind(&Factory::buildRook, this, std::placeholders::_1);
        m_buildPiece['N'] = std::bind(&Factory::buildKnight, this, std::placeholders::_1);
        m_buildPiece['B'] = std::bind(&Factory::buildBishop, this, std::placeholders::_1);
        m_buildPiece['P'] = std::bind(&Factory::buildPawn, this, std::placeholders::_1);
    }

    std::unique_ptr<Piece> buildPieceFactory(char playerPiece) {
        bool is_upper = std::isupper(playerPiece);
        std::map<char, buildPiece>::iterator iter = m_buildPiece.find(std::toupper(playerPiece));
        return(iter != m_buildPiece.end()) ? iter->second(is_upper) : nullptr;
    }

private:
    typedef std::function<std::unique_ptr<Piece>(bool)> buildPiece;
    std::map<char, buildPiece> m_buildPiece;
};
