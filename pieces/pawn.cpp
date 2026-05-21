#include "pawn.h"

bool Pawn::validMove(Position newPosition, Board& board) {
    
}

std::vector<Position> Pawn::calculatePosibleNewPositions(Board& board) {
    std::vector<Position> ans;
    ans.reserve(3);
    Position posiblePosition(position.row, position.colum);
    int i;
    if (color) {
        posiblePosition.row--;
        for (i = position.colum - 1; i <= position.colum + 1; i++) {
            posiblePosition.colum = i;
            if (validPosition(posiblePosition) && !isWhite(board.positionInfo(posiblePosition))) {
                ans.push_back(posiblePosition);
            }
        }
    }
    else {
        posiblePosition.row++;
        for (i = position.colum - 1; i <= position.colum + 1; i++) {
            posiblePosition.colum = i;
            if (validPosition(posiblePosition) && !isBlack(board.positionInfo(posiblePosition))) {
                ans.push_back(posiblePosition);
            }
        }
    }
    return ans;
}