#include "Pawn.h"

Pawn::Pawn(){
    type = PAWN;
    team = BLACK;
    alive = true;
    x = 0;
    y = 0;
    findValidMoves(); // TODO This needs to be called in main instead
}
Pawn::Pawn(faction team, bool alive, int x, int y){
    this->type = PAWN;
    this->team = team;
    this->alive = alive;
    this->x = x;
    this->y = y;
    findValidMoves();
}

bool Pawn::validMove(int boardIndex) {
    int x = indexToX(boardIndex);
    int y = indexToY(boardIndex);
    if (WHITE == team) {
        if ((x == this->x-1 && y == this->y) ||
            (x == this->x-2 && y == this->y)) {
            return true;
        }
    } else {
        if ((x == this->x+1 && y == this->y) ||
            (x == this->x+2 && y == this->y)) {
            return true;
        }
    }
    return false;
}