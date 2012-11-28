#include "TicTacToe.h"
#include <cstdlib>
using namespace std;
aoenuthasoeuth
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

char TicTacToe::getBoardElement(int x, int y)
{
	return board[x][y];
}

// prints the board and defines player 't' as winner
// adds 1 to player t's score
void TicTacToe::endGame(char p)
{
	switch (p)
	{
		// winner
		case 'X':
			++score[0];
			break;
		case 'O':
			++score[1];
			break;

		// no winner
		case 'T':
		default:
			++score[2];
			break;
	}
}

int TicTacToe::getScore(int i)
{
	if (i<3 && i>=0)
		return score[i];
	else return -1;
}

int TicTacToe::getScore(char p)
{
	switch (p)
	{
		case 'X':
			return score[0];
			break;
		case 'O':
			return score[1];
			break;
		case 'T':
			return score[2];
			break;
		default:
			return 0;
			break;
	}

	return 0;
}

// places player s's symbol on the board
bool TicTacToe::addSymbol(char s, int x, int y)
{
	if (x > 2 || x < 0)
		return false;

	if (y > 2 || y < 0)
		return false;

	if (board[x][y] == ' ')
	{
		board[x][y] = s;
		return true;
	}
	return false;
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
	for (int i=0; i<3; ++i)
	{
		for (int j=0; j<3; ++j)
		{
			if (board[i][j] == ' ')
				return false;
		}
	}
	return true;
}

void TicTacToe::resetScore()
{
	for (int i=0; i<3; ++i)
		score[i] = 0;
}
