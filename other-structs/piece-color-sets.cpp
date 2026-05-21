#include "piece-color-sets.h"


bool isBlack(int pieceNumber) {
    bool ans = false;
    if (pieceNumber >= 0 && pieceNumber < 7)
        ans = true;

    return ans;
}


bool isWhite(int pieceNumber) {
    bool ans = false;
    if (pieceNumber >= 7 && pieceNumber < 13)
        ans = true;

    return ans;
}