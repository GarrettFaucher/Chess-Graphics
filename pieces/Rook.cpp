#include "Rook.h"

Rook::Rook(){
    type = ROOK;
    team = BLACK;
    alive = true;
    x = 0;
    y = 0;
    findValidMoves();
}
Rook::Rook(faction team, bool alive, int x, int y){
    this->type = ROOK;
    this->team = team;
    this->alive = alive;
    this->x = x;
    this->y = y;
    findValidMoves();
}


bool Rook::validMove(int boardIndex) {
    int x = indexToX(boardIndex);
    int y = indexToY(boardIndex);
    if ((x == this->x || y == this->y) &&
        (x != this->x || y != this->y)) {
        return true;
    }
    return false;
}