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

void Bishop::draw() {
    Quad r;
    if(team == BLACK){
        r = Quad({0,0,0},{(getX()*100)+50, (getY()*100)+50}, 50, 50);
        r.draw();
        glColor3f(1,1,1);
    }
    else{
        r = Quad({1,1,1},{(getX()*100)+50, (getY()*100)+50}, 50, 50);
        r.draw();
        glColor3f(0,0,0);
    }
    std::string label = "Bishop";
    glRasterPos2i(getX()*100 + 27 ,getY()*100 +50);
    for (const char &letter : label) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
}
