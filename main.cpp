#include <iostream>
#include "ChessPiece.h"
#include "Board.h"

using namespace std;

void getInput(int &x, int &y);

int main() {
    Board gameBoard;
    gameBoard.fileToBoard("../boards/default.csv"); // "../boards/default.csv"
    cout << "Below is the game of chess.\n" <<
         "The top left coordinates are (0, 0), and the bottom right is (7, 7).\n" <<
         "To move a piece first put the coords in of the one to move, then its new location.\n" <<
         "To end the game, when the first x coord is asked, put \"-1\".\n\n" <<
         gameBoard.toString() << endl;

    int x;
    int y;
    faction teamTurn = WHITE;
    // Loop to take user input and move pieces as long as not "-1"
    while (x != -1 && y != -1 && x != -1 && y != -1) {
        if (teamTurn == 1) {
            cout << "White";
        } else {
            cout << "Black";
        }
        cout << " team's turn." << endl;
        getInput(x, y);
        ChessPiece *currentPiece = gameBoard.getPiece(x, y, teamTurn);
        while (currentPiece == NULL) {
            cout << boolalpha << "Invalid piece chosen. Make sure to choose a ";
            if (teamTurn == 1) {
                cout << "white";
            } else {
                cout << "black";
            }
            cout << " piece." << endl;
            getInput(x, y);
            currentPiece = gameBoard.getPiece(x, y, teamTurn);
        }
        cout << currentPiece->toStringValidMoves() << endl;
        gameBoard.popPiece(x, y, teamTurn);

        // Move the piece
        cout << "What option should the piece move to?" << endl;
        int option;
        cin >> option;
        gameBoard.movePieceToOption(currentPiece, option);
        gameBoard.checkCollisions();

        cout << gameBoard.toString() << endl;
        if (gameBoard.getWhiteTurn()) {
            gameBoard.setWhiteTurn(false);
            teamTurn = BLACK;
        } else {
            gameBoard.setWhiteTurn(true);
            teamTurn = WHITE;
        }
    }

    return 0;
}

// Gets input from user and double checks to make sure it is within valid range
void getInput(int &x, int &y) {
    cin >> x;
    cin >> y;
    while(x >= 8 || x <= -2 || y >= 8 || y <= -2) {
        if (x >= 8 || x <= -2) {
            cout << "x must be 0 <= x <= 7" << endl;
            cin >> x;
        } else if (y >= 8 || y <= -2) {
            cout << "y must be 0 <= y <= 7" << endl;
            cin >> y;
        }
    }
}