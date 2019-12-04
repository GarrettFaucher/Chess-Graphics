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
    // TODO: Specify movement logic for valid moves, don't allow to move to space with ally
    // This is out of the scope of this project.
    if (1) {
        return true;
    }
    return false;
}