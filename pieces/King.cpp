#include "King.h"

King::King(){
    type = PAWN;
    team = BLACK;
    alive = true;
    x = 0;
    y = 0;
    findValidMoves();
}
King::King(faction team, bool alive, int x, int y){
    this->type = KING;
    this->team = team;
    this->alive = alive;
    this->x = x;
    this->y = y;
    findValidMoves();
}

bool King::getInCheck() const{
    return inCheck;
}
void King::setInCheck(bool inCheck){
    this->inCheck = inCheck;
}

bool King::validMove(int boardIndex) {
    int x = indexToX(boardIndex);
    int y = indexToY(boardIndex);
    if ((x == this->x-1 && y == this->y) ||
        (x == this->x+1 && y == this->y) ||
        (x == this->x && y == this->y-1) ||
        (x == this->x && y == this->y+1) ||
        (x == this->x-1 && y == this->y-1) ||
        (x == this->x+1 && y == this->y+1) ||
        (x == this->x-1 && y == this->y+1) ||
        (x == this->x+1 && y == this->y-1)) {
        return true;
    }
    return false;
}