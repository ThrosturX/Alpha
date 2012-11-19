#include "TicTacToe.h"

using namespace std;

// Constructar, initializes scores as 0-0-0 (player 1, player 2, tie)
TicTacToe::TicTacToe()
{

}

// Plays the game
void TicTacToe::play()
{

}

// Returns a copy of the board
char** TicTacToe::getBoard()
{
	char** copy = new char*[3];
	for (int i=0; i<3; ++i)
	{
		copy[i] = new char[3];
		for (int j=0; j<3; ++j)
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

}

// prints the board
void TicTacToe::print()
{

}

// clears the board
void TicTacToe::clear()
{

}

// checks for a winner, player s is the winner
bool TicTacToe::winner(char &p)
{
	return true; 
}

// determine if the board is full
bool TicTacToe::fullBoard()
{
	return true;
}

// logic for a player to move
void TicTacToe::playerInput(char &p)
{
	
}


