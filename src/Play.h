#ifndef PLAY_H
#define PLAY_H

#include <iostream>
#include "TicTacToe.h"

class Play
{
public:
	Play();

	void start();	// play tic tac toe

private:
	TicTacToe game;
	void printBoard();		// print tic tac toe board
	void printScore();
	void printWinner(char t);
	
	void getInput();			// get input from user
	

};

#endif // PLAY_H
