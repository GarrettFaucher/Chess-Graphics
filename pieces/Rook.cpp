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

void Rook::draw() {
    Quad r = Quad({.5,0,.2},{(getX()*100)+50, (getY()*100)+50}, 50, 50);
    r.draw();
    if(team == BLACK){
        glColor3f(0,0,0);
    }
    else{
        glColor3f(1,1,1);
    }
    std::string label = "Rook";
    glRasterPos2i(getX()*100 + 35 ,getY()*100 +50);
    for (const char &letter : label) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
}
