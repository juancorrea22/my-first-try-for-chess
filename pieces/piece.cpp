#include "piece.h"


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

Piece::Piece(Position position, int type) {
    this->position = position;
    this->type = type;
}

// getters
Position Piece::getPosition() {
    return position;
}

int Piece::getType() {
    return type;
}

bool Piece::getColor() {
    return color;
}


// setters
void Piece::setPosition(Position newPosition) {
    position = newPosition;
}

void Piece::setType(int newType) {
    type = newType;
}

void Piece::setColor(bool newColor) {
    color = newColor;
}