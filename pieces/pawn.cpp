#include "pawn.h"

bool Pawn::validMove(Position newPosition, Board& board) {
    bool ans = false;
    // si el peon es blanco
    if (color) {
        // se intenta mover hacia arriba y no hay nada
        if (newPosition.column == position.column - 1 && position.column > 0 && newPosition.row == position.row && 
        board.positionInfo(newPosition) == 0) {
            ans == true;
        }
        else {
            Position posiblePosition1, posiblePosition2;
            posiblePosition1 = Position(position.row - 1, position.column - 1);
            posiblePosition2 = Position(position.row + 1, position.column - 1);
            if (newPosition == posiblePosition1 && validPosition(posiblePosition1) && 
            !sameColor(board.positionInfo(posiblePosition1), board.positionInfo(position))) {
                ans = true;
            }
            else if ((newPosition == posiblePosition2 && validPosition(posiblePosition2)) &&
            !sameColor(board.positionInfo(posiblePosition2), board.positionInfo(position))) {
                ans = true;
            }
        }
    }
    // si el peon es negro
    else {
        // se intenta mover hacia abajo
        if (newPosition.column == position.column + 1 && newPosition.row == position.row &&
        board.positionInfo(newPosition) == 0) {
            ans = true;
        }
        else {
            Position posiblePosition1, posiblePosition2;
            posiblePosition1 = Position(position.row - 1, position.column + 1);
            posiblePosition2 = Position(position.row + 1, position.column + 1);
            if (newPosition == posiblePosition1 && validPosition(posiblePosition1) && 
            !sameColor(board.positionInfo(posiblePosition1), board.positionInfo(position))) {
                ans = true;
            }
            else if ((newPosition == posiblePosition2 && validPosition(posiblePosition2)) &&
            !sameColor(board.positionInfo(posiblePosition2), board.positionInfo(position))) {
                ans = true;
            }
        }
    }

    return ans;
}

std::vector<Position> Pawn::calculatePosibleNewPositions(Board& board) {
    std::vector<Position> ans;
    ans.reserve(3);
    Position posiblePosition(position.row, position.column);
    int i;
    if (color) {
        posiblePosition.row--;
        for (i = position.column - 1; i <= position.column + 1; i++) {
            posiblePosition.column = i;
            if (validPosition(posiblePosition) && !isWhite(board.positionInfo(posiblePosition))) {
                ans.push_back(posiblePosition);
            }
        }
    }
    else {
        posiblePosition.row++;
        for (i = position.column - 1; i <= position.column + 1; i++) {
            posiblePosition.column = i;
            if (validPosition(posiblePosition) && !isBlack(board.positionInfo(posiblePosition))) {
                ans.push_back(posiblePosition);
            }
        }
    }
    return ans;
}