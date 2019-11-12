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
    int x = boardIndex % 8;
    int y = boardIndex - x;
    // TODO: Specify movement logic for valid moves, don't allow to move to space with ally
    // This is out of the scope of this project.
    if (1) {
        return true;
    }
    return false;
}