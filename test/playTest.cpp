#include "../src/TicTacToe.h"
#include "../UnitTest++/src/UnitTest++.h"

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

	board.addSymbol('X',2,1);
	
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

	board.addSymbol('X',0,0);
	
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
}

int main()
{
	return UnitTest::RunAllTests(); 
}
