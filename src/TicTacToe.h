#ifndef TICTACTOE_H
#define TICTACTOE_H 

#include <iostream>

class TicTacToe
{
public:
	TicTacToe();
	
//	void play();
	void clear();

	char** getBoard();
	bool winner(char &p);
	void playerInput(char &p);
	//void print();
	void endGame(char p);
	void addSymbol(char s, int x, int y);
	bool fullBoard();
	int* getScore();

private:
	char board[3][3];
	int score[3];	// X - O - TIE
};

#endif
