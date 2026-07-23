#include "rook.h"

bool Rook::validMove (Position newPosition, Board& board) {
    bool ans = false;

    if (board.positionInfo(newPosition) == 0 || !sameColor(board.positionInfo(newPosition), board.positionInfo(position))) {

        char movementDirection = positionMovementChange(position, newPosition);

        ans = true;

        if (movementDirection == 'U') {
            int i = position.row;
            while (i > newPosition.row && ans) {
                if (sameColor(board.cordsInfo(i, position.column), board.positionInfo(position))) {
                    ans = false;
                }
                i--;
            }
        }
        else if (movementDirection == 'D') {
            int i = position.row;
            while (i < newPosition.row && ans) {
                if (sameColor(board.cordsInfo(i, position.column), board.positionInfo(position))) {
                    ans = false;
                }
                i++;
            }
        }
        else if (movementDirection == 'L') {
            int j = position.column;
            while(j > newPosition.column && ans) {
                if (sameColor(board.cordsInfo(position.row, j), board.positionInfo(position))) {
                    ans = false;
                }
                j--;
            }
        }
        else if (movementDirection == 'R') {
            int j = position.column;
            while(j < newPosition.column && ans) {
                if (sameColor(board.cordsInfo(position.row, j), board.positionInfo(position))) {
                    ans = false;
                }
                j++;
            }
        }
        else {
            ans = false;
        }
    }

    return ans;
}

std::vector<Position> Rook::calculatePosibleNewPositions(Board& board) {
    std::vector<Position> ans;
    Position newPos;
    int move;

    int up, down, left, right, cont;
    up = down = left = right = 0;

    bool stopUp, stopDown, stopLeft, stopRight;
    stopUp = stopDown = stopLeft = stopRight = false;

    auto stop = [&stopUp, &stopDown, &stopRight, &stopLeft]() {
        return stopUp && stopDown && stopLeft && stopRight;
    };

    auto factors = [&cont]() {
        std::pair<int, int> ij = {0, 0};
        int step = (cont % 8) + 1;

        if (cont < 8)       ij.first  = step;
        else if (cont < 16) ij.first  = -step;
        else if (cont < 24) ij.second = step;
        else if (cont < 32) ij.second = -step;
        
        return ij;
    };

    auto stopFactors = [&stopUp, &stopDown, &stopLeft, &stopRight](int& i, int& j) {
        if (i > 0)       stopUp = true;
        else if (i < 0)  stopDown = true;
        else if (j > 0)  stopRight = true;
        else if (j < 0)  stopLeft = true;
        return;
    };

    auto validStop = [&stopUp, &stopDown, &stopLeft, &stopRight](int& i, int& j) {
        if (i > 0)       return stopUp;
        else if (i < 0)  return stopDown;
        else if (j > 0)  return stopRight;
        else if (j < 0)  return stopLeft;
        return false;
    };

    std::pair<int, int> ij;
    cont = 0;
    while (cont < 32 && !stop()) {
        ij = factors();
        if (!validStop(ij.first, ij.second)) {
            newPos = Position(position.row + ij.first, position.column + ij.second);
            if (validPosition(newPos)) {
                move = board.getBoard()[newPos.row][newPos.column];
                if (move == 0) {
                    ans.push_back(newPos);
                }
                else {
                    if (!sameColor(move, type)) {
                        ans.push_back(newPos);
                    }
                    stopFactors(ij.first, ij.second);
                }
            }
            else {
                stopFactors(ij.first, ij.second);
            }
        }
        cont++;
    }

    return ans;
}