#include "Queen.h"

Queen::Queen(){
    type = QUEEN;
    team = BLACK;
    alive = true;
    x = 0;
    y = 0;
    findValidMoves();
}
Queen::Queen(faction team, bool alive, int x, int y){
    this->type = QUEEN;
    this->team = team;
    this->alive = alive;
    this->x = x;
    this->y = y;
    findValidMoves();
}


bool Queen::validMove(int boardIndex) {
    int x = indexToX(boardIndex);
    int y = indexToY(boardIndex);
    int deltaX = x - this->x;
    int deltaY = y - this->y;
    if (((x == this->x || y == this->y) ||
         ( deltaX ==  deltaY) ||
         ( deltaX == -deltaY) ||
         (-deltaX ==  deltaY) ||
         (-deltaX == -deltaY)) &&
        (x != this->x || y != this->y)) {
        return true;
    }
    return false;
}