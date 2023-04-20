#include "..\include\Board.h"

Board::Board(const std::string& bStr): m_currentPlayerIsWhite(true)
{
    clearAndBuildBoard(bStr);
}

int Board::codeRespone(const std::string& move)
{
    

    Position src = { move[0] - 'a', move[1] - '1' };
    Position dst = { move[2] - 'a', move[3] - '1' };

    if (isEmpty(src))
        return 11;

    if (isRival(src))
        return 12;

    if (isCurrentTurnPiece(dst))
        return 13;
    if (!m_board[src.x][src.y]->isAcceptableMove(src, dst) || isWayBloacked(src, dst))
        return 21;

    if (isPossibleChess(src, dst))
        return 31;

    update(src, dst);

    if (isGameOver())
        return 41;

    return 42;

}

void Board::clearAndBuildBoard(const std::string& bStr)
{
    for (int row = 0; row < ROWS; ++row)
        for (int col = 0; col < COLS; ++col)
            m_board[row][col] = nullptr;

    m_king[1] = DEFULT_POSTION; //white king
    m_king[0] = DEFULT_POSTION; //black king

    // now build board
    Factory factory;
    for (auto i = 0; i < bStr.size(); ++i) {
        auto row = i / ROWS;
        auto col = i % COLS;
        if (bStr[i] == 'K')
            m_king[1] = { row, col };
        else if (bStr[i] == 'k')
            m_king[0] = { row, col };

      m_board[row][col] = factory.buildPieceFactory(bStr[i]);
    }

}

bool Board::isEmpty(const Position source) const
{
    return m_board[source.x][source.y] == nullptr;
}

bool Board::isRival(const Position source) const
{
    return m_board[source.x][source.y]->getPieceColor() != m_currentPlayerIsWhite;
}

bool Board::isCurrentTurnPiece(const Position source) const
{
    return !isEmpty(source) && !isRival(source);
}

bool Board::isWayBloacked(const Position& source, const Position& dest) const
{
    int dx = dest.x - source.x;
    int dy = dest.y - source.y;

    if (dx != 0 && dy != 0 && std::abs(dx) != std::abs(dy)) {
        return false;
    }

    int x_move = (dx > 0) ? 1 : ((dx < 0) ? -1 : 0);
    int y_move = (dy > 0) ? 1 : ((dy < 0) ? -1 : 0);
    Position currentPostion = source;
    currentPostion.x += x_move;
    currentPostion.y += y_move;
    while (currentPostion.x != dest.x || currentPostion.y != dest.y) {
        if (!isEmpty(currentPostion)) {
            return true;
        }
        currentPostion.x += x_move;
        currentPostion.y += y_move;
    }
    return false;

}

bool Board::isPossibleChess(const Position& source, const Position& dest)
{
    auto temp = std::move(m_board[dest.x][dest.y]);
    m_board[dest.x][dest.y] = std::move(m_board[source.x][source.y]);
    if (isKing(dest)) 
        m_king[m_board[dest.x][dest.y]->getPieceColor()] = dest;


    bool UnderAttack = isGameOver();
    if (isKing(dest)) 
        m_king[m_board[dest.x][dest.y]->getPieceColor()] = source;


    m_board[source.x][source.y] = std::move(m_board[dest.x][dest.y]);
    m_board[dest.x][dest.y] = std::move(temp);
    return UnderAttack;

}

bool Board::isKing(const Position& location) const
{
    return m_board[location.x][location.y]->getPlayer() == Players::KING;
}

bool Board::isGameOver() const
{
    auto opponent_moves = getOpponentMoves();

    for (int i = 0; i < opponent_moves.size(); ++i) {
        auto opponent_move = opponent_moves[i];
        if (m_board[opponent_move.x][opponent_move.y]->isAcceptableMove(opponent_move, m_king[m_currentPlayerIsWhite]) &&
            !isWayBloacked(opponent_move, m_king[m_currentPlayerIsWhite])) {
            return true;
        }
    }

    return false;


}

bool Board::isPawn(const Position& location) const
{
    return m_board[location.x][location.y]->getPlayer() == Players::PAWN;
}

void Board::update(const Position soucre, const Position dest)
{
    if (isKing(soucre))
        m_king[m_board[soucre.x][soucre.y]->getPieceColor()] = dest;


    if (isPawn(soucre))
    {
        Pawn* thePawn = dynamic_cast<Pawn*>(m_board[soucre.x][soucre.y].get());
        thePawn -> setFirstMove();
    }
    m_board[dest.x][dest.y] = std::move(m_board[soucre.x][soucre.y]);
    m_board[soucre.x][soucre.y] = nullptr;
    m_currentPlayerIsWhite = !m_currentPlayerIsWhite;
}



std::vector<Position> Board::getOpponentMoves() const
{
   std::vector<Position> enemyMoves;
    for (int x = 0; x < ROWS; x++) {
        for (int y = 0; y < COLS; y++) {
            Position currentPos = { x, y };
            if (!isEmpty(currentPos) && !isCurrentTurnPiece(currentPos)) {
                enemyMoves.push_back(currentPos);
            }
        }
    }
    return enemyMoves; 

}






