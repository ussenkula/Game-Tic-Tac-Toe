#include <iostream>

using namespace std;

const int ROW = 3;
const int COL = 3;
const char X = 'X';
const char O = 'O';
const char SPACE = ' ';

void displayInstructions();
void showBoard(char theBoard[][COL], int, int);
void getMove(char theBoard[][COL], int, int, char);
bool isFull(char theBoard[][COL], int, int);
bool checkWin(char theBoard[][COL], int, int);
bool checkDraw(bool checkWin);
bool repeat();

int main()
{
    int row = ROW;
    int col = COL;
    char move;
    int winner, player;
    char theBoard[ROW][COL];

    //play game as many times as users want
    do
    {
        player = 2;

        //declare empty board
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                theBoard[i][j] = SPACE;
            }
        }

        //show instruction of game
        displayInstructions();
        cout << endl;

        //play game until game finishes or someone wins
        do
        {
            cout << "Player " << player % 2 + 1 << ", it is you turn!" << endl;
            showBoard(theBoard, row, col);
            if (player % 2 + 1 == 1)
                move = X;
            else
                move = O;
            getMove(theBoard, row, col, move);
            cout << endl << endl;
            player++;
        } while (!isFull(theBoard, row, col) && !checkWin(theBoard, row, col));


        //show board at the end of the game
        showBoard(theBoard, row, col);

        //announce the winner
        if (checkWin(theBoard, row, col))
        {
            if (player % 2 == 1)
                winner = 1;
            else
                winner = 2;
            cout << "Player " << winner << " win!" << endl;
        }
        //announce draw
        else if (checkDraw(checkWin(theBoard, row, col)))
            cout << "It's draw!" << endl;

    } while (repeat());


    return 0;
}

//function that shows rules of the game
void displayInstructions()
{
    cout << "Welcome to the game Tic Tac Toe!" << endl << endl;;
    cout << "Rules:" << endl;
    cout << "The object of Tic Tac Toe is to get three in a row." << endl;
    cout << "You play on a three by three game board. " << endl;
    cout << "The first player is known as X and the second is O." << endl;
    cout << "Players alternate placing Xs and Os on the game board until either" << endl;
    cout << "opponent has three in a row or all nine squares are filled." << endl;
    cout << "X always goes first, and in the event that no one has three in a row, " << endl;
    cout << "the stalemate is called a cat game." << endl << endl;
    cout << "Let's play!" << endl << endl;
}

//function prints out board with current moves
void showBoard( char theBoard[][COL], int row, int col)
{
    cout << "Right now board looks like that: " << endl;
    cout << "To make your move, please enter numbers of place on the board" << endl;
    cout << "First number is number of row, second number is number of column" << endl;
    cout << "   1  2  3" << endl;
    for( int i = 0; i < row; i++)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < col; j++)
        {
            cout << "[" << theBoard[i][j] << "]";
        }
        cout << endl;
    }
}

//function asks users to make move and makes move to the right board location
void getMove(char theBoard[][COL], int row, int col, char move)
{
    int response1, response2;
    cout << "Make your move: ";
    cin >> response1 >> response2;
    while ( response1 < 1 || response1 > (row + 1) || response2 < 1 ||
           response2 > (col + 1) || theBoard[response1 - 1][response2 - 1] != ' ' || cin.fail()	)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error... try again" << endl;
        cout << "Make sure that you are not out of range of rows and columns, and place you want to choose is empty" << endl;
        cin >> response1 >> response2;
    }

    theBoard[response1 - 1][response2 - 1] = move;
}

//function checks if board is full
bool isFull(char theBoard[][COL], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (theBoard[i][j] == ' ')
                return false;
        }
    }
    return true;
}

//function checks winning combinations
bool checkWin(char theBoard[][COL], int row, int col)
{
    if ((theBoard[0][0] == theBoard[0][1] && theBoard[0][1] == theBoard[0][2] && theBoard[0][0] != SPACE) ||
        (theBoard[1][0] == theBoard[1][1] && theBoard[1][1] == theBoard[1][2] && theBoard[1][0] != SPACE) ||
        (theBoard[2][0] == theBoard[2][1] && theBoard[2][1] == theBoard[2][2] && theBoard[2][0] != SPACE) ||
        (theBoard[0][0] == theBoard[1][0] && theBoard[1][0] == theBoard[2][0] && theBoard[0][0] != SPACE) ||
        (theBoard[0][1] == theBoard[1][1] && theBoard[1][1] == theBoard[2][1] && theBoard[0][1] != SPACE) ||
        (theBoard[0][2] == theBoard[1][2] && theBoard[1][2] == theBoard[2][2] && theBoard[0][2] != SPACE) ||
        (theBoard[0][0] == theBoard[1][1] && theBoard[1][1] == theBoard[2][2] && theBoard[0][0] != SPACE) ||
        (theBoard[0][2] == theBoard[1][1] && theBoard[1][1] == theBoard[2][0] && theBoard[0][2] != SPACE) )
            return true;
    else
        return false;
}

//function check if it is draw
bool checkDraw(bool checkWin)
{
    if(!checkWin)
        return true;
    else
        return false;
}

//function asks users if they want to play again
bool repeat()
{
    char response;
    cout << "Would you like to play again? (Enter y/n) ";
    cin >> response;
    while (cin.fail() || (response != 'y' && response != 'n'))
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Try again: " << endl;
        cin >> response;
    }
    if (response == 'y')
        return true;
    else if (response == 'n')
        return false;
}
