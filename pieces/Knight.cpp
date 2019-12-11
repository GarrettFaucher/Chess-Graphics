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

void Knight::draw() {
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
    std::string label = "Knight";
    glRasterPos2i(getX()*100 + 28 ,getY()*100 +50);
    for (const char &letter : label) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

}
