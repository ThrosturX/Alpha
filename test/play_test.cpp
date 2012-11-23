#include "../src/Play.h"
#include "../UnitTest++/src/UnitTest++.h"
#include <sstream>

namespace
{
TEST(printScore_1)
{
	// redirect output	
	std::ostringstream oss;
	std::streambuf* coutConsole = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf()); 

	Play player;

	player.getGame().endGame('X');

	player.printScore();

	CHECK_EQUAL("The score is:\n\tX\tO\tTie\n\t1\t0\t0\n\n",oss.str());	
	
	//restore cout to console again
	std::cout.rdbuf(coutConsole);
}

TEST(printScore_2)
{
	// redirect output	
	std::ostringstream oss;
	std::streambuf* coutConsole = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf()); 

	Play player;

	player.getGame().endGame('X');
	player.getGame().endGame('O');
	player.getGame().endGame('T');
	player.getGame().endGame('4');

	player.printScore();

	CHECK_EQUAL("The score is:\n\tX\tO\tTie\n\t1\t1\t2\n\n", oss.str());	

	
	//restore cout to console again
	std::cout.rdbuf(coutConsole);
}

TEST(printWinner_1)
{
	// redirect output	
	std::ostringstream oss;
	std::streambuf* coutConsole = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf()); 

	Play player;

	player.printWinner('X');
	CHECK_EQUAL(oss.str(), "Player X wins!\n\n");	

	
	//restore cout to console again
	std::cout.rdbuf(coutConsole);
}

TEST(printWinner_2)
{
	// redirect output	
	std::ostringstream oss;
	std::streambuf* coutConsole = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf()); 

	Play player;

	player.printWinner('O');
	CHECK_EQUAL(oss.str(), "Player O wins!\n\n");	
	
	//restore cout to console again
	std::cout.rdbuf(coutConsole);
}

TEST(printWinner_3)
{
	// redirect output	
	std::ostringstream oss;
	std::streambuf* coutConsole = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf()); 

	Play player;

	player.printWinner('T');
	CHECK_EQUAL(oss.str(), "It's a tie!\n\n");	
	
	//restore cout to console again
	std::cout.rdbuf(coutConsole);
}

TEST(printBoard_test_1)
{
	Play game;
	game.getGame().addSymbol('X', 0, 0);
	game.getGame().addSymbol('X', 0, 1);
	game.getGame().addSymbol('X', 0, 2);
	game.getGame().addSymbol('X', 1, 0);
	game.getGame().addSymbol('X', 1, 1);
	game.getGame().addSymbol('X', 1, 2);
	game.getGame().addSymbol('X', 2, 0);
	game.getGame().addSymbol('X', 2, 1);
	game.getGame().addSymbol('X', 2, 2);

	//redirect cout so we can test the output
	std::ostringstream oss;
	std::streambuf* coutConsole = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf()); 
	game.printBoard();
	//restore cout to console again
	std::cout.rdbuf(coutConsole);
	CHECK_EQUAL(oss.str(), "-----\nX X X \n-----\nX X X \n-----\nX X X \n-----\n");
}
	
TEST(printError_1)
{
	Play game;
	
	//redirect cout so we can test the output
	std::ostringstream oss;
	std::streambuf* coutConsole = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf()); 

	game.printError(1);

	CHECK_EQUAL(oss.str(), "Please enter your input in the correct format.\nExample: A 2 or B 0.\n");

	//restore cout to console again
	std::cout.rdbuf(coutConsole);
}

TEST(printError_1)
{
	Play game;
	
	//redirect cout so we can test the output
	std::ostringstream oss;
	std::streambuf* coutConsole = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf()); 

	game.printError(1);

	CHECK_EQUAL(oss.str(), "Please enter your input in the correct format.\nExample: A 2 or B 0.\n");

	//restore cout to console again
	std::cout.rdbuf(coutConsole);
}

}
