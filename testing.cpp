#include <iostream>
#include "ChessPiece.h"
#include "Board.h"
#include "Pieces/King.h"
#include "Pieces/Queen.h"
#include "Pieces/Bishop.h"
#include "Pieces/Rook.h"
#include "Pieces/Knight.h"
#include "Pieces/Pawn.h"

#include <iomanip>
using namespace std;

bool testBoard();
bool testPieces();
bool testValidMoves();
bool testMovePieceToOption();

int main() {
    if (testBoard()) {
        cout << "Passed all test cases for testBoard!" << endl;
    }
    if (testPieces()) {
        cout << "Passed all test cases for testPieces!" << endl;
    }
    if (testValidMoves()) {
        cout << "Passed all test cases for testValidMoves!" << endl;
    }
    if (testMovePieceToOption()) {
        cout << "Passed all test cases for testMovePieceToOption!" << endl;
    }
    return 0;
}


bool testBoard() {

    bool passed = true;

    Board defaultBoard;
    defaultBoard.fileToBoard("../boards/default.csv");
    if (defaultBoard.getPiece(0,0,BLACK)->toStringBoardInfo() != "BR  ") {
        cout << "FAILED 1st test case for testBoard." << endl;
        passed = false;
    }
    if (defaultBoard.getPiece(1,0,BLACK)->toStringBoardInfo() != "BP  ") {
        cout << "FAILED 2nd test case for testBoard." << endl;
        passed = false;
    }
    if (defaultBoard.getPiece(6,7,WHITE)->toStringBoardInfo() != "WP  ") {
        cout << "FAILED 3rd test case for testBoard." << endl;
        passed = false;
    }
    if (defaultBoard.getPiece(7,7,WHITE)->toStringBoardInfo() != "WR  ") {
        cout << "FAILED 4th test case for testBoard." << endl;
        passed = false;
    }

    Board challengeBoard;
    defaultBoard.fileToBoard("../boards/challenge1.csv");
    if (defaultBoard.getPiece(1,1,BLACK)->toStringBoardInfo() != "BP  ") {
        cout << "FAILED 5th test case for testBoard." << endl;
        passed = false;
    }
    if (defaultBoard.getPiece(0,7,BLACK)->toStringBoardInfo() != "BKG ") {
        cout << "FAILED 6th test case for testBoard." << endl;
        passed = false;
    }
    if (defaultBoard.getPiece(4,3,WHITE)->toStringBoardInfo() != "WP  ") {
        cout << "FAILED 7th test case for testBoard." << endl;
        passed = false;
    }
    if (defaultBoard.getPiece(7,3,WHITE)->toStringBoardInfo() != "WR  ") {
        cout << "FAILED 8th test case for testBoard." << endl;
        passed = false;
    }

    return passed;
}

bool testPieces() {

    bool passed = true;

    Bishop b1 = Bishop();
    if (b1.getType() != BISHOP && b1.getTeam() != BLACK && b1.getAlive() != true && b1.getX() != 0 && b1.getY() != 0) {
        cout << "FAILED 1st test case for testPieces." << endl;
        passed = false;
    }
    Bishop b2 = Bishop(WHITE, true, 1, 1);
    if (b2.getType() != BISHOP && b2.getTeam() != WHITE && b2.getAlive() != true && b2.getX() != 1 && b2.getY() != 1) {
        cout << "FAILED 2nd test case for testPieces." << endl;
        passed = false;
    }

    King kg1 = King();
    if (kg1.getType() != KING && kg1.getTeam() != BLACK && kg1.getAlive() != true && kg1.getX() != 0 && kg1.getY() != 0) {
        cout << "FAILED 3rd test case for testPieces." << endl;
        passed = false;
    }
    King kg2 = King(WHITE, true, 1, 1);
    if (kg2.getType() != KING && kg2.getTeam() != WHITE && kg2.getAlive() != true && kg2.getX() != 1 && kg2.getY() != 1) {
        cout << "FAILED 4th test case for testPieces." << endl;
        passed = false;
    }

    Knight kn1 = Knight();
    if (kn1.getType() != KNIGHT && kn1.getTeam() != BLACK && kn1.getAlive() != true && kn1.getX() != 0 && kn1.getY() != 0) {
        cout << "FAILED 3rd test case for testPieces." << endl;
        passed = false;
    }
    Knight kn2 = Knight(WHITE, true, 1, 1);
    if (kn2.getType() != KNIGHT && kn2.getTeam() != WHITE && kn2.getAlive() != true && kn2.getX() != 1 && kn2.getY() != 1) {
        cout << "FAILED 4th test case for testPieces." << endl;
        passed = false;
    }

    Pawn p1 = Pawn();
    if (p1.getType() != PAWN && p1.getTeam() != BLACK && p1.getAlive() != true && p1.getX() != 0 && p1.getY() != 0) {
        cout << "FAILED 3rd test case for testPieces." << endl;
        passed = false;
    }
    Pawn p2 = Pawn(WHITE, true, 1, 1);
    if (p1.getType() != PAWN && p1.getTeam() != WHITE && p1.getAlive() != true && p1.getX() != 1 && p1.getY() != 1) {
        cout << "FAILED 4th test case for testPieces." << endl;
        passed = false;
    }

    Queen q1 = Queen();
    if (q1.getType() != QUEEN && q1.getTeam() != BLACK && q1.getAlive() != true && q1.getX() != 0 && q1.getY() != 0) {
        cout << "FAILED 3rd test case for testPieces." << endl;
        passed = false;
    }
    Queen q2 = Queen(WHITE, true, 1, 1);
    if (q2.getType() != QUEEN && q2.getTeam() != WHITE && q2.getAlive() != true && q2.getX() != 1 && q2.getY() != 1) {
        cout << "FAILED 4th test case for testPieces." << endl;
        passed = false;
    }

    Rook r1 = Rook();
    if (r1.getType() != ROOK && r1.getTeam() != BLACK && r1.getAlive() != true && r1.getX() != 0 && r1.getY() != 0) {
        cout << "FAILED 3rd test case for testPieces." << endl;
        passed = false;
    }
    Rook r2 = Rook(WHITE, true, 1, 1);
    if (r2.getType() != ROOK && r2.getTeam() != WHITE && r2.getAlive() != true && r2.getX() != 1 && r2.getY() != 1) {
        cout << "FAILED 4th test case for testPieces." << endl;
        passed = false;
    }

    return passed;
}

bool testValidMoves() {

    bool passed = true;

    Board defaultBoard;
    defaultBoard.fileToBoard("../boards/default.csv");
    vector<int> movesFound = defaultBoard.getPiece(0,0,BLACK)->getValidMoves();
    vector<int> movesExpected;
    for (int i = 0; 64 > i; i++) {
        movesExpected.push_back(i);
    }
    if (movesFound != movesExpected) {
        cout << "FAILED 1st test case for testValidMoves." << endl;
        passed = false;
    }

    return passed;
}

bool testMovePieceToOption() {

    bool passed = true;

    Pawn* p1 = new Pawn(WHITE, true, 6, 0);
    p1->moveToValidMove(0);

    if (p1->getX() != 5, p1->getY() != 0) {
        cout << "FAILED 1st test case for testMovePieceToOption." << endl;
        passed = false;
    }

    p1->moveToValidMove(0);
    if (p1->getX() != 4, p1->getY() != 0) {
        cout << "FAILED 1st test case for testMovePieceToOption." << endl;
        passed = false;
    }

    return passed;
}