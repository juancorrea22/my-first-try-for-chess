#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>

#include "../other-structs/position.h"

// 1-7: Peon
// 2-8: Torre
// 3-9: Caballo
// 4-10: Alfil
// 5-11: Reyna
// 6-12: Rey


class Board {
    private:
        int board[8][8];
    
    public:
        Board();
        const int (*getBoard() const)[8] {
            return board;
        }
        int positionInfo(Position& position);
        void printBoard();
};

#endif