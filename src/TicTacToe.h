#ifndef TICTACTOE_H
#define TICTACTOE_H 

class TicTacToe
{
public:
	TicTacToe();
	
	void clear();

	char** getBoard();
	bool winner(char &p);
	void endGame(char p);
	void addSymbol(char s, int x, int y);
	bool fullBoard();
	int getScore(int i);
	int getScore(char p);
	char* getVersion();

private:
	char board[3][3];
	int score[3];	// X - O - TIE
};

#endif
