#include "Play.h"
#include "TicTacToe.h"

using namespace std;

Play::Play()
{
	game = new TicTacToe();
}

Play::~Play()
{
	delete game;
}

// spawns a tic tac toe object and manipulates it's logic to play
void Play::start()
{
	// X starts
	char temp, player = 'X';
	string s;

	do
	{
		printBoard();

		if (getInput(player) == 1)
		{
			start();
			return;
		}

		// swap players
		if (player == 'X') player = 'O';
		else player = 'X';
	}
	while(!game->winner(temp) && !game->fullBoard());

	// check who wins
	if (game->winner(temp))
		game->endGame(temp);
	else	// tie
		game->endGame('T');

	printBoard();
	printScore();

	cout << "Play again? ";
	getline(cin, s);	

	if (s.length() > 0 && tolower(s.at(0)) == 'y')
		start();
	else cout << "Please come again." << endl << endl;
}


void Play::printBoard()
{
	for(int i = 0; i<3; i++){
		cout << "-----" << endl;
		for(int j = 0; j<3; j++){
			cout << getGame().getBoardElement(i, j) << " ";
		}
		cout << "\n";
	}
	cout << "-----\n";
}
void Play::printScore()
{
	cout << "The score is:" << endl
		<< "\tX\tO\tTie" << endl;
		for (int i=0; i<3; ++i)
		{
			cout <<	"\t" << game->getScore(i);
		}
		cout << endl << endl;
}

void Play::printWinner(char p)
{
	if (p == 'X' || p == 'O')
		cout << "Player " << p << " wins!" << endl << endl;
	else
		cout << "It's a tie!" << endl << endl;
}

void Play::printError(int e)
{
	switch (e)
	{	
		case 1:
			cout << "Please enter your input in the correct format." <<
			endl << "Example: A 2 or B 0." << endl;
			break;
		case 2:
			cout << "This tile is already taken." <<
			endl << "Please select a free tile." << endl;
			break;
		default:
			cout << "Unexpected error occurred." << endl;
			break;
	}
}

int Play::getInput(char p)
{
	bool valid;
	int x, y;
	string coord;

	cout << "Player " << p << "\'s turn ";

	do
	{	
		getline(cin,coord);
		if (coord.length() < 3)
		{
			printError(1);
			continue;
		}
		else if (coord == "exit" || coord == "quit")
		{
			cout << "Thank you for playing." << endl;
			exit(0);
		}
		else if (coord == "reset" || coord == "start again")
		{
			game->clear();
			return 1;
		}
	
		valid = true;

		// get row
		char row = tolower(coord.at(0));

		// get collumn	
		int collumn = coord.at(2) - '0';
	
		switch(row)
		{
			case 'a':
				y = 0;
				break;
			case 'b':
				y = 1;
				break;
			case 'c':
				y = 2;
				break;
			default:
				valid = false;
				break;
		}

		// normalize array index
		if (collumn >= 1 && collumn <= 3)
			x = --collumn;

		if (!valid)
			printError(1);
	
	// addSymbol should be a boolean and return whether or not the thing worked or not. Yo.

	}
	while(!valid);

	while (!game->addSymbol(p, x, y))
	{
		printError(2);
		getInput(p);	
	}
	
	return 0;
}

TicTacToe& Play::getGame()
{
	return *game;
}
