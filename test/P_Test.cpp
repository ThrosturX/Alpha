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

// logic missing

	CHECK_EQUAL(oss.str(), "Player X wins!/n/n");	

	
	//restore cout to console again
	std::cout.rdbuf(coutConsole);
}


}
