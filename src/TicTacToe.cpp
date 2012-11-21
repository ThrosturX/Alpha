#include "TicTacToe.h"

using namespace std;

// Constructar, initializes scores as 0-0-0 (player 1, player 2, tie)
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

}

// places player s's symbol on the board
void TicTacToe::addSymbol(char s, int x, int y)
{
	board[x][y] = s;
}

// prints the board
void TicTacToe::print()
{

}

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
	
}


