#ifndef PLAY_H
#define PLAY_H
aoseuthasotnuhsnaouthaosnuhoe
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>
#include "TicTacToe.h"

using namespace std;

class Play
{
public:
	Play();
	~Play();
	void start();	// play tic tac toe

	void printBoard();		// print tic tac toe board
	void printScore();
	void printWinner(char p);
	void printError(int e);		// print error e
	int getInput(char p, string pos);			// get input from user
	string getPos();


	TicTacToe& getGame();

private:
	TicTacToe* game;
};

#endif // PLAY_H
