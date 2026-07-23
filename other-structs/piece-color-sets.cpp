#include "piece-color-sets.h"


bool isBlack(const int pieceNumber) {
    bool ans = false;
    if (pieceNumber >= 0 && pieceNumber < 7)
        ans = true;

    return ans;
}


bool isWhite(const int pieceNumber) {
    bool ans = false;
    if (pieceNumber >= 7 && pieceNumber < 13)
        ans = true;

    return ans;
}


bool sameColor(const int piece1, const int piece2) {
    return (isBlack(piece1) && isBlack(piece2)) || (isWhite(piece1) && isWhite(piece2));
}