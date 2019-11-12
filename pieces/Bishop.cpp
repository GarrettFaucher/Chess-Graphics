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
    int x = boardIndex % 8;
    int y = boardIndex - x;
    // TODO: Specify movement logic for valid moves, don't allow to move to space with ally
    // This is out of the scope of this project.
    if (1) {
        return true;
    }
    return false;
}