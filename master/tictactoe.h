#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

class TicTacToe
{
public:
	TicTacToe();
	void addSymbol(char symbol, int x, int y);
	void print();
	void clear();
	void play();

private:
	char array[3][3];
	int score[3];
	bool winner(char &s);
	bool fullBoard();
	void playerMove(char &p);
	void endGame(char t);
};

#endif // BOARD_H
