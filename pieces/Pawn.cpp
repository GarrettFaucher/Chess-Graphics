#include "Pawn.h"

Pawn::Pawn(){
    type = PAWN;
    team = BLACK;
    alive = true;
    firstMove = true;
    x = 0;
    y = 0;
    findValidMoves();
}
Pawn::Pawn(faction team, bool alive, int x, int y){
    this->type = PAWN;
    this->team = team;
    this->alive = alive;
    firstMove = true;
    this->x = x;
    this->y = y;
    findValidMoves();
}

bool Pawn::validMove(int boardIndex) {
    int x = indexToX(boardIndex);
    int y = indexToY(boardIndex);

    if (WHITE == team) {
        if ((x == this->x && y == this->y-1) || (((x == this->x-1) || (x == this->x+1)) && y == this->y-1)) {
            return true;
        } else if (firstMove && (x == this->x && y == this->y-2)) {
            return true;
        }
    } else {
        if ((x == this->x && y == this->y+1) || (((x == this->x-1) || (x == this->x+1)) && y == this->y+1)) {
            return true;
        } else if (firstMove && (x == this->x && y == this->y+2)) {
            return true;
        }
    }
    return false;
}

void Pawn::movePiece(int x, int y) {
    if (this->y != y) {
        firstMove = false;
    }
    this->x = x;
    this->y = y;
}

void Pawn::draw() {
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
    std::string label = "Pawn";
    glRasterPos2i(getX()*100 + 35 ,getY()*100 +50);
    for (const char &letter : label) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

}
