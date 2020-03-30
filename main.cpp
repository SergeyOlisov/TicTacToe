#include <iostream>
#include <fstream>
#include "Game.h"

void OutputConsole(int x, int y, char player);
void OutputFileInfo(int x, int y, char player);

using namespace std;

const int SIZE = 3;
char gameBoard[SIZE][SIZE] =
        {
                {' ', ' ', ' '},
                {' ', ' ', ' '},
                {' ', ' ', ' '}
        };

void ShowBoard(char gameBoard[SIZE][SIZE]);

int main()
{
    int coordinateX, coordinateY;
    bool winX, winO;
    winX = false;
    winO = false;
    int endgame = 0, stepX = 0, stepY = 0;

    ShowBoard(gameBoard);

    Game game;
    while (endgame < 1) {

        while (stepX < 1) {
            cout << "Move X: " << endl << "Enter coordinate X: ";
            cin >> coordinateX;
            coordinateX -= 1;
            cout << endl << "Enter coordinate Y: ";
            cin >> coordinateY;
            coordinateY -= 1;
            cout << endl;

            if (gameBoard[coordinateX][coordinateY] == ' ') {
                gameBoard[coordinateX][coordinateY] = 'X';
                game.Message[0] = OutputConsole;
                game.Message[1] = OutputFileInfo;

                game.Move(coordinateX,coordinateY, 'X');

                stepX = 1;
                stepY = 0;
            } else {
                if (coordinateX < 0 || coordinateX > 2 || coordinateY < 0 || coordinateY > 2) {
                    cout << "Nope!" << endl;
                }
                if (gameBoard[coordinateX][coordinateY] == 'O') {
                    gameBoard[coordinateX][coordinateY] = 'O';
                    cout << "Nope!" << endl;
                }
                if (gameBoard[coordinateX][coordinateY] == 'X') {
                    cout << "Nope!" << endl;
                }

                cout << "You can not do it this way! Repeat the move." << endl;
            }

        }

        ShowBoard(gameBoard);

        if ((gameBoard[0][0] == 'X' && gameBoard[0][1] == 'X' && gameBoard[0][2] == 'X') ||
            (gameBoard[1][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[1][2] == 'X') ||
            (gameBoard[2][0] == 'X' && gameBoard[2][1] == 'X' && gameBoard[2][2] == 'X') ||
            (gameBoard[0][0] == 'X' && gameBoard[1][0] == 'X' && gameBoard[2][0] == 'X') ||
            (gameBoard[0][1] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][1] == 'X') ||
            (gameBoard[0][2] == 'X' && gameBoard[1][2] == 'X' && gameBoard[2][2] == 'X') ||
            (gameBoard[0][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][2] == 'X') ||
            (gameBoard[0][2] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][0] == 'X')) {
            winX = true;
        } else {
            if ((gameBoard[0][0] != ' ' && gameBoard[0][1] != ' ' && gameBoard[0][2] != ' ') &&
                (gameBoard[1][0] != ' ' && gameBoard[1][1] != ' ' && gameBoard[1][2] != ' ') &&
                (gameBoard[2][0] != ' ' && gameBoard[2][1] != ' ' && gameBoard[2][2] != ' ')) {
                cout << "Draw!";
                endgame = 1;
                stepX=1;
                stepY=1;
            }
        }
        if (winX) {
            cout << "X WINS!!!" << endl;
            endgame = 1;
            stepY = 1;
        }
        while (stepY < 1) {
            cout << "Move Y: " << endl << "Enter coordinate X: ";
            cin >> coordinateX;
            coordinateX -= 1;
            cout << endl << "Enter coordinate Y: ";
            cin >> coordinateY;
            coordinateY -= 1;
            cout << endl;

            if (gameBoard[coordinateX][coordinateY] == ' ') {
                gameBoard[coordinateX][coordinateY] = 'O';
                game.Message[0] = OutputConsole;
                game.Message[1] = OutputFileInfo;

                game.Move(coordinateX,coordinateY, 'O');

                stepY = 1;
                stepX = 0;
            } else {
                if (coordinateX < 0 || coordinateX > 2 || coordinateY < 0 || coordinateY > 2) {
                    cout << "Nope!" << endl;
                }
                if (gameBoard[coordinateX][coordinateY] == 'X') {
                    gameBoard[coordinateX][coordinateY] = 'X';
                    cout << "Nope!" << endl;
                }
                if (gameBoard[coordinateX][coordinateY] == 'O') {
                    cout << "Nope!" << endl;
                }

                cout << "You can not do it this way! Repeat the move." << endl;
            }

        }

        ShowBoard(gameBoard);

        if ((gameBoard[0][0] == 'O' && gameBoard[0][1] == 'O' && gameBoard[0][2] == 'O') ||
            (gameBoard[1][0] == 'O' && gameBoard[1][1] == 'O' && gameBoard[1][2] == 'O') ||
            (gameBoard[2][0] == 'O' && gameBoard[2][1] == 'O' && gameBoard[2][2] == 'O') ||
            (gameBoard[0][0] == 'O' && gameBoard[1][0] == 'O' && gameBoard[2][0] == 'O') ||
            (gameBoard[0][1] == 'O' && gameBoard[1][1] == 'O' && gameBoard[2][1] == 'O') ||
            (gameBoard[0][2] == 'O' && gameBoard[1][2] == 'O' && gameBoard[2][2] == 'O') ||
            (gameBoard[0][0] == 'O' && gameBoard[1][1] == 'O' && gameBoard[2][2] == 'O') ||
            (gameBoard[0][2] == 'O' && gameBoard[1][1] == 'O' && gameBoard[2][0] == 'O')) {
            winO = true;
        } else {
            if ((gameBoard[0][0] != ' ' && gameBoard[0][1] != ' ' && gameBoard[0][2] != ' ') &&
                (gameBoard[1][0] != ' ' && gameBoard[1][1] != ' ' && gameBoard[1][2] != ' ') &&
                (gameBoard[2][0] != ' ' && gameBoard[2][1] != ' ' && gameBoard[2][2] != ' ')) {
                cout << "Draw!" << endl;
                endgame = 1;
                stepY=1;
                stepX = 1;
            }
        }
        if (winO) {
            cout << "O WINS!!!" << endl;
            endgame = 1;
            stepX = 1;
        }
    }
}

void ShowBoard(char gameBoard[SIZE][SIZE])
{
    for (int i=0; i<SIZE; i++) {
        cout << "-------" << endl;
        cout << "|" << gameBoard[0][i] << '|';
        cout << gameBoard[1][i] << '|';
        cout << gameBoard[2][i] << '|' << endl;
    }
    cout << "-------" << endl;
    system("pause");
    cout << endl << endl;
}
void OutputConsole(int x, int y, char player)
{
    cout << "Player - " << player << " made move " << "x - " << x+1 << ", y - " << y+1 << endl;
}
void OutputFileInfo(int x, int y, char player)
{
    ofstream file("file.log", ios::app);
    if (file.is_open())
    {
        file << "Player - " << player << " made move " << "x - " << x+1 << ", y - " << y+1 << endl;
    }
    file.close();
}