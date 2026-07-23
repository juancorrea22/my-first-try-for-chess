#include "piece.h"


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