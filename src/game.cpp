#include <iostream>
#include "TicTacToe.h"
#include "Play.h" 

const char* VERSION = "1.0.0";

int main()
{
	using namespace std;

	cout << "Tic Tac Toe version " << VERSION <<
	endl << "\t by TEAM ALPHA" << endl << endl;

	Play player;

	player.start();

	return 0;
}

