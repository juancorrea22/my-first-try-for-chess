#include "horse.h"

bool Horse::validMove (Position newPosition, Board& board) {
    bool ans = false;
    if (!sameColor(board.positionInfo(newPosition), board.positionInfo(position))) {
        if (position.column + 1 == newPosition.column || position.column - 1 == newPosition.column) {
            if (position.row + 2 == newPosition.row || position.row - 2 == newPosition.row) {
                ans = true;
            }
        }
        else if (position.row + 1 == newPosition.row || position.row - 1 == newPosition.row) {
            if (position.column + 2 == newPosition.column || position.column - 2 == newPosition.column) {
                ans = true;
            }
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
        
        Position posiblePosition(position.row + i, position.column + j);

        if (validPosition(posiblePosition)) {
            int destinyPosition = board.positionInfo(posiblePosition);
            
            bool sameColor = (color && isWhite(destinyPosition)) || (!color && isBlack(destinyPosition));

            if (!sameColor) {
                ans.push_back(posiblePosition);
            }
        }
    }

    return ans;
}