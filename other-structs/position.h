#ifndef POSITION_H
#define POSITION_H

struct Position {
    int row;
    int column;
    Position() = default;
    Position(int r, int c);

    bool operator==(const Position& other) const;
};

bool validPosition(Position& position);

char positionMovementChange(Position& initialPosition, Position& lastPosition);

#endif