#include "Play.h"
#include "TicTacToe.h"

using namespace std;

Play::Play()
{
	//TicTacToe* newGame = new TicTacToe();
	game = new TicTacToe();
	//game.clear();
}

// spawns a tic tac toe object and manipulates it's logic to play
void Play::start()
{

}

void Play::printBoard()
{
	char** board = getGame().getBoard();
	
	for(int i = 0; i<3; i++){
		cout << "-----" << endl;
		for(int j = 0; j<3; j++){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "-----\n";
}

void Play::printScore()
{
	cout << "The score is:" << endl
		<< "\tX\tO\tTie" << endl
		<< "\tscore[0]\tScore[1]\tScore[2]" << endl;	
}

void Play::printWinner(char p)
{
	if (p == 'X' || p == 'O')
		cout << "Player " << p << " wins!" << endl << endl;
	else
		cout << "It's a tie!" << endl << endl;
/*
	switch(p)
	{
		// winner
		case 'X':
		break;	
	}*/
}

void Play::getInput()
{

}

TicTacToe Play::getGame()
{
	return *game;
}
