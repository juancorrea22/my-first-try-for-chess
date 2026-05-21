#ifndef HORSE_H
#define HORSE_H

#include "piece.h"

class Horse : public Piece {
    public:
        Horse(Position position, int type) : Piece(position, type) {}

        bool validMove (Position newPosition, Board& board) override;
        
        std::vector<Position> calculatePosibleNewPositions(Board& board) override;
};


#endif