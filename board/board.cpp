#include "board.h"


Board::Board() {
    // 1-7: Peon
    // 2-8: Torre
    // 3-9: Caballo
    // 4-10: Alfil
    // 5-11: Reyna
    // 6-12: Rey

    const int initBoard[8][8] = { // crear matriz inicial para el tablero
        {2, 3, 4, 5, 6, 4, 3, 2},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {7, 7, 7, 7, 7, 7, 7, 7},
        {8, 9, 10, 11, 12, 10, 9, 8},
    };

    // llenar la matriz de la clase
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = initBoard[i][j];
        }
    }
}

int Board::positionInfo(Position& position) {
    return board[position.row][position.column];
}

int Board::cordsInfo(const int& x, const int& y) {
    return board[x][y];
}

void Board::printBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (j < 7) printf("%d ", board[i][j]);
            else if (j == 7) printf("%d\n", board[i][j]);
        }
    }
}