#include "Bishop.h"

Bishop::Bishop(){
    type = BISHOP;
    team = BLACK;
    alive = true;
    x = 0;
    y = 0;
    findValidMoves();
}
Bishop::Bishop(faction team, bool alive, int x, int y){
    this->type = BISHOP;
    this->team = team;
    this->alive = alive;
    this->x = x;
    this->y = y;
    findValidMoves();
}


bool Bishop::validMove(int boardIndex) {
    int x = indexToX(boardIndex);
    int y = indexToY(boardIndex);
    int deltaX = x - this->x;
    int deltaY = y - this->y;
    if (( deltaX ==  deltaY) ||
        ( deltaX == -deltaY) ||
        (-deltaX ==  deltaY) ||
        (-deltaX == -deltaY) &&
        (x != this->x || y != this->y)) {
        return true;
    }
    return false;
}