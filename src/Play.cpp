#include "Play.h"
#include "TicTacToe.h"

using namespace std;

/*Play::Play()
{
	game.clear();
}*/

// spawns a tic tac toe object and manipulates it's logic to play
void Play::start()
{

}

void Play::printBoard()
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

void Play::printScore()
{

}

void Play::printWinner(char p)
{

}

void Play::getInput()
{

}

TicTacToe Play::getGame()
{
	return game;
}
