#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
    public: 
        Rook(Position position, int type) : Piece(position, type) {}

        bool validMove (Position newPosition, Board& board) override;

        std::vector<Position> calculatePosibleNewPositions(Board& board) override;
        
};

#endif