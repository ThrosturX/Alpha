#ifndef TICTACTOE_H
#define TICTACTOE_H 

class TicTacToe
{
public:
	TicTacToe();
	
	void clear();

	char** getBoard();
	char getBoardElement(int x, int y);
	bool winner(char &p);
	void endGame(char p);
	bool addSymbol(char s, int x, int y);
	bool fullBoard();
	int getScore(int i);
	int getScore(char p);
	void resetScore();

private:
	char board[3][3];
	int score[3];	// X - O - TIE
};

#endif
