#ifndef TicTacToe
#define TicTacToe

#include <iostream>

class TicTacToe
{
public:
	TicTacToe();
	
	void resetBoard();

private:
	char board[3][3];
	
	bool winner();
	void playerInput(char p);
	void printBoard();
};

#endif
