#include "../src/TicTacToe.h"
#include "../UnitTest++/src/UnitTest++.h"
#include <sstream>

namespace
{
TEST(add_symbol_1)
{
	TicTacToe board;
	
	char arr_correct[3][3];
	for (int i=0; i<3; ++i)
	{
		for (int j=0; j<3; ++j)
			arr_correct[i][j] = ' ';
	}

	arr_correct[0][0] = 'X';

	board.addSymbol('X',0,0);
	
	CHECK_ARRAY2D_CLOSE(arr_correct, board.getBoard(),3,3, 0);
}

TEST(add_symbol_2)
{
	TicTacToe board;
	
	char arr_correct[3][3];
	for (int i=0; i<3; ++i)
	{
		for (int j=0; j<3; ++j)
			arr_correct[i][j] = ' ';
	}

	arr_correct[2][1] = 'O';

	board.addSymbol('O',2,1);
	
	CHECK_ARRAY2D_CLOSE(arr_correct, board.getBoard(),3,3, 0);
}

TEST(add_symbol_3)
{
	TicTacToe board;
	
	char arr_correct[3][3];
	for (int i=0; i<3; ++i)
	{
		for (int j=0; j<3; ++j)
			arr_correct[i][j] = ' ';
	}

	arr_correct[0][2] = 'X';

	board.addSymbol('X',0,2);
	
	CHECK_ARRAY2D_CLOSE(arr_correct, board.getBoard(),3,3, 0);
}

TEST(add_symbol_4)
{
	TicTacToe board;

	char arr_correct[3][3];
	for (int i=0; i<3; ++i)
		for (int j=0; j<3; ++j)
			arr_correct[i][j]= ' ';

	arr_correct[0][1] = 'X';
	arr_correct[1][1] = 'O';

	board.addSymbol('X',0,1);
	board.addSymbol('O',1,1);
	board.addSymbol('X',1,1);	// shouldn't change anything

	CHECK_ARRAY2D_CLOSE(arr_correct, board.getBoard(),3,3, 0);

}

TEST(winner_test_1)
{
	TicTacToe game;
	game.addSymbol('X', 0, 0);
	game.addSymbol('X', 0, 1);
	game.addSymbol('X', 0, 2);
	char player;
	CHECK_EQUAL(game.winner(player),true);
}

TEST(winner_test_2)
{
	TicTacToe game;
	game.addSymbol('O', 0, 0);
	game.addSymbol('O', 1, 1);
	game.addSymbol('O', 2, 2);
	char player;
	CHECK_EQUAL(game.winner(player), true);
}

TEST(winner_test_3)
{
	TicTacToe game;
	game.addSymbol('O', 0, 2);
	game.addSymbol('O', 1, 1);
	game.addSymbol('O', 2, 0);
	char player;
	CHECK_EQUAL(game.winner(player), true);
}

TEST(fullBoard_test_1)
{
	TicTacToe game;
	game.addSymbol('X', 0, 0);
	game.addSymbol('X', 0, 1);
	game.addSymbol('O', 0, 2);
	game.addSymbol('O', 1, 0);
	game.addSymbol('O', 1, 1);
	game.addSymbol('X', 1, 2);
	game.addSymbol('X', 2, 0);
	game.addSymbol('X', 2, 1);
	game.addSymbol('O', 2, 2);
	CHECK_EQUAL(game.fullBoard(), true);
}

TEST(fullBoard_test_2)
{
	TicTacToe game;
	game.addSymbol('O', 0, 0);
	game.addSymbol('O', 0, 1);
	game.addSymbol('O', 0, 2);
	game.addSymbol('O', 1, 0);
	game.addSymbol('O', 1, 1);
	game.addSymbol('O', 1, 2);
	game.addSymbol('O', 2, 0);
	game.addSymbol('O', 2, 1);
	CHECK_EQUAL(game.fullBoard(), false);
}

/*
TEST(printBoard_test_1)
{
	TicTacToe game;
	game.addSymbol('X', 0, 0);
	game.addSymbol('X', 0, 1);
	game.addSymbol('X', 0, 2);
	game.addSymbol('X', 1, 0);
	game.addSymbol('X', 1, 1);
	game.addSymbol('X', 1, 2);
	game.addSymbol('X', 2, 0);
	game.addSymbol('X', 2, 1);
	game.addSymbol('X', 2, 2);

	//redirect cout so we can test the output
	std::ostringstream oss;
	std::streambuf* coutConsole = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf()); 
	game.print();
	//restore cout to console again
	std::cout.rdbuf(coutConsole);
	CHECK_EQUAL(oss.str(), "-----\nX X X \n-----\nX X X \n-----\nX X X \n-----\n");

}
*/
/*
TEST(endGame_1)
{
	//redirect cout so we can test the output
	std::ostringstream oss;
	std::streambuf* coutConsole = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf()); 

	TicTacToe board;

	char winner = 'X';

	int score[3] = {1,0,0};	

	board.endGame(winner);

	CHECK_ARRAY_EQUAL(score, board.getScore(), 3);		

	//restore cout to console again
	std::cout.rdbuf(coutConsole);
	CHECK_EQUAL(oss.str(), "Player X wins!\n\n");
}

TEST(endGame_2)
{
	TicTacToe board;

	//redirect cout so we can test the output
	std::ostringstream oss;
	std::streambuf* coutConsole = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf()); 
	
	int score[3] = {4,2,0};	

	board.endGame('X');
	board.endGame('X');
	board.endGame('X');
	board.endGame('X');
	board.endGame('O');
	board.endGame('O');

	CHECK_ARRAY_EQUAL(score, board.getScore(), 3);		
	
	//restore cout to console again
	std::cout.rdbuf(coutConsole);
	CHECK_EQUAL(oss.str(), "Player X wins!\n\n");
	CHECK_EQUAL(oss.str(), "Player X wins!\n\n");
	CHECK_EQUAL(oss.str(), "Player X wins!\n\n");
	CHECK_EQUAL(oss.str(), "Player O wins!\n\n");
	CHECK_EQUAL(oss.str(), "Player O wins!\n\n");
}

TEST(endGame_3)
{
	TicTacToe board;

	//redirect cout so we can test the output
	std::ostringstream oss;
	std::streambuf* coutConsole = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf()); 

	int score[3] = {2,4,2};	

	board.endGame('X');
	board.endGame('O');
	board.endGame('X');
	board.endGame('O');
	board.endGame('T');
	board.endGame('O');
	board.endGame('4');
	board.endGame('O');

	CHECK_ARRAY_EQUAL(score, board.getScore(), 3);		
	
	//restore cout to console again
	std::cout.rdbuf(coutConsole);
	CHECK_EQUAL(oss.str(), "Player X wins!\n\n");
	CHECK_EQUAL(oss.str(), "Player O wins!\n\n");
	CHECK_EQUAL(oss.str(), "Player X wins!\n\n");
	CHECK_EQUAL(oss.str(), "Player O wins!\n\n");
	CHECK_EQUAL(oss.str(), "It's a tie!\n\n");
	CHECK_EQUAL(oss.str(), "Player O wins!\n\n");
	CHECK_EQUAL(oss.str(), "It's a tie!\n\n");
	CHECK_EQUAL(oss.str(), "Player O wins!\n\n");
}
*/
}

int main()
{
	return UnitTest::RunAllTests(); 
}
