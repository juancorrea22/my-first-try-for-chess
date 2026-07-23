#include "position.h"

Position::Position(int r, int c) : row(r), column(c) {}

bool Position::operator==(const Position& other) const {
    return row == other.row && column == other.column;
}

bool validPosition(Position& position) {
    bool ans = true;
    
    if (position.column < 0 || position.column > 7 ||
    position.row < 0 || position.column > 7) ans = false;

    return ans;
}

char positionMovementChange(Position& initialPosition, Position& lastPosition) {
    char ans = 'X'; // valor X como valor inicial de error
    if (initialPosition == lastPosition) {
        ans = 'S'; // se mantiene en el mismo lugar
    }
    else if (initialPosition.column == lastPosition.column) {
        if (initialPosition.row < lastPosition.row) {
            ans = 'U'; // se mueve hacia arriba
        }
        else if (initialPosition.row > lastPosition.row) {
            ans = 'D'; // se mueve hacia abajo
        }
    }
    else if (initialPosition.row == lastPosition.row) {
        if (initialPosition.column < lastPosition.column) {
            ans = 'R'; // se mueve hacia la derecha
        }
        else if (initialPosition.column > lastPosition.column) {
            ans = 'L'; // se mueve a la izquierda
        }
    }

    return ans;
}