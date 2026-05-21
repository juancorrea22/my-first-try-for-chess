#include "position.h"

Position::Position(int r, int c) : row(r), colum(c) {}

bool Position::operator==(const Position& other) const {
    return row == other.row && colum == other.colum;
}

bool validPosition(Position& position) {
    bool ans = true;
    
    if (position.colum < 0 || position.colum > 7 ||
    position.row < 0 || position.colum > 7) ans = false;

    return ans;
}