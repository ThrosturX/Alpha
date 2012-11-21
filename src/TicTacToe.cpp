#include "TicTacToe.h"
#include <cstdlib>
using namespace std;

// Constructer, initializes scores as 0-0-0 (player 1, player 2, tie)
// Initializes every tile on the board as ' '
TicTacToe::TicTacToe()
{
	for(int i = 0; i<3; i++)
	{
		score[i] = 0;
		for(int j = 0; j<3; j++)
			board[i][j] = ' ';
	}
}

// Plays the game
void TicTacToe::play()
{

}

// Returns a copy of the board
char** TicTacToe::getBoard()
{
	char** copy = new char*[3];
	for(int i = 0; i<3; ++i)
	{
		copy[i] = new char[3];
		for(int j = 0; j<3; ++j)
		{
			copy[i][j] = board[i][j];
		}
	}
	return copy;
}

// prints the board and defines player 't' as winner
// adds 1 to player t's score
void TicTacToe::endGame(char t)
{
//	print();
	
	if (t == 'X' || t == 'O')
		cout << "Player " << t << " wins!" << endl << endl;
	else
		cout << "It's a tie!" << endl << endl;

	switch (t)
	{
		// winner
		case 'X':
			score[0]++;
			break;
		case 'O':
			score[1]++;
			break;

		// no winner
		case 'T':
		default:
			score[2]++;
			break;
	}
}

int* TicTacToe::getScore()
{
	return score;
}

// places player s's symbol on the board
void TicTacToe::addSymbol(char s, int x, int y)
{
	if (board[x][y] == ' ')
		board[x][y] = s;
}
/*
// prints the board
void TicTacToe::print()
{
	for(int i = 0; i<3; i++){
		cout << "-----" << endl;
		for(int j = 0; j<3; j++){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "-----\n";
}
*/
// clears the board
void TicTacToe::clear()
{
	for(int i=0; i<3; ++i)
	{
		for(int j=0; j<3; ++j)
			board[i][j] = ' ';
	}
}

// checks for a winner, player s is the winner
bool TicTacToe::winner(char &p)
{
	char player[2];
	player[0] = 'X';
	player[1] = 'O';
	for(int i = 0; i<2; i++)
	{
		for(int j = 0; j<3; j++)
		{
			if(board[0][j] == player[i] && board[1][j] == player[i] && board[2][j] == player[i])
			{
				p = player[i];
				return true;
			}
			if(board[j][0] == player[i] && board[j][1] == player[i] && board[j][2] == player[i])
			{
				p = player[i];
				return true;
			}
			if(board[0][0] == player[i] && board[1][1] == player[i] && board[2][2] == player[i])
			{
				p = player[i];
				return true;
			}
			if(board[0][2] == player[i] && board[1][1] == player[i] && board[2][0] == player[i])
			{
				p = player[i];
				return true;
			}
		}
	}
	return false;
}

// determine if the board is full
bool TicTacToe::fullBoard()
{
	bool istrue;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(board[i][j] == 'X' || board[i][j] == 'O') {
				istrue = true;
			}
			else {
				istrue = false;
				break;
			}
		}
	}
	return istrue;
}

// logic for a player to move
void TicTacToe::playerInput(char &p)
{
	//Oli is doing this
	while(p!='X' && p!= 'O')
	{
	    cout << "Invalid character, please enter either X or O " << endl;
	    cin >> p;
	}
	char a;
	int y;

	cout << "please enter the column name (A,B,C) and the row number of where you'd like to play \n";
	cout << "For example, A 2 or B 0" << endl;
    cin >> a >> y;

    while(a != ('A','B','C') && y != (0,1,2))
    {
        cout << "Please enter your input in the right format. Example A 2 or B 0" << endl;
        cin >> a >> y;
    }
    int x = a - 65; //converts A B C to 0 1 2
    addSymbol(p,x,y);



}


