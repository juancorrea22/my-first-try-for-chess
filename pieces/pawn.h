#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece {
    public:
        Pawn(Position position, int type) : Piece(position, type) {}

        bool validMove (Position newPosition, Board& board) override;
    
        std::vector<Position> calculatePosibleNewPositions(Board& board) override;


    
};

#endif