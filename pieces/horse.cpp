#include "horse.h"

bool Horse::validMove (Position newPosition, Board& board) {
    bool ans = false;
    if (position.colum + 1 == newPosition.colum || position.colum - 1 == newPosition.colum) {
        if (position.row + 2 == newPosition.row || position.row - 2 == newPosition.row) {
            ans = true;
        }
    }
    else if (position.row + 1 == newPosition.row || position.row - 1 == newPosition.row) {
        if (position.colum + 2 == newPosition.colum || position.colum - 2 == newPosition.colum) {
            ans = true;
        }
    }
    return ans;
}

std::vector<Position> Horse::calculatePosibleNewPositions(Board& board) {
    std::vector<Position> ans;
    ans.reserve(8);
    int a, i, j;
    for (a = 0; a < 8; a++) {
        if (a < 4) {
            i = 1; j = 2;
        }
        else {
            i = 2; j = 1;
        }
        
        if ((a & (1 << 1)) != 0) j *= -1;
        if ((a & (1 << 0)) == 0) i *= -1;
        
        Position posiblePosition(position.row + i, position.colum + j);

        if (validPosition(posiblePosition)) {
            int piezaDestino = board.positionInfo(posiblePosition);
            
            bool esMismoColor = (color && isWhite(piezaDestino)) || (!color && isBlack(piezaDestino));

            if (!esMismoColor) {
                ans.push_back(posiblePosition);
            }
        }
    }

    return ans;
}