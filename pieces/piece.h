#ifndef PIECE_H
#define PIECE_H

#include <utility>
#include <cmath>
#include <vector>
#include <string>

#include "../board/board.h"
#include "../other-structs/position.h"
#include "../other-structs/piece-color-sets.h"


class Piece {
    protected:
        Position position;
        int type;
        bool color; // 0: black, 1: white

        // 1-7: Peon
        // 2-8: Torre
        // 3-9: Caballo
        // 4-10: Alfil
        // 5-11: Reyna
        // 6-12: Rey

    public:
        Piece(Position position, int type);

        // getters
        Position getPosition();
        int getType();
        bool getColor();

        // setters
        void setPosition(Position newPosition);
        void setType(int newType);
        void setColor(bool newColor);

        virtual bool validMove(Position newPosition, Board& board) = 0;

        virtual std::vector<Position> calculatePosibleNewPositions(Board& board) = 0;

        virtual ~Piece() = default;
};


#endif