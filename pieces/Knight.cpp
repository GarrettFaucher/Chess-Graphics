#include "Knight.h"

Knight::Knight(){
    type = KNIGHT;
    team = BLACK;
    alive = true;
    x = 0;
    y = 0;
    findValidMoves();
}
Knight::Knight(faction team, bool alive, int x, int y){
    this->type = KNIGHT;
    this->team = team;
    this->alive = alive;
    this->x = x;
    this->y = y;
    findValidMoves();
}


bool Knight::validMove(int boardIndex) {
    int x = indexToX(boardIndex);
    int y = indexToY(boardIndex);
    if ((x == this->x+1 && y == this->y-2) ||
        (x == this->x+1 && y == this->y+2) ||
        (x == this->x+2 && y == this->y-1) ||
        (x == this->x+2 && y == this->y+1) ||
        (x == this->x-1 && y == this->y-2) ||
        (x == this->x-1 && y == this->y+2) ||
        (x == this->x-2 && y == this->y-1) ||
        (x == this->x-2 && y == this->y+1)) {
        return true;
    }
    return false;
}