#include "Play.h"
#include "TicTacToe.h"
#include <iomanip>


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
	game->clear();
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
    int length = 13;
    cout << "   A   B   C\n";
	for(int i = 0; i<3; i++){
        if(i != 0)
        {
            cout << setfill(' ') << setw(length)  << "--- --- ---";
            cout << endl;
        }
        cout << i+1 << ": ";
		for(int j = 0; j<3; j++){
            if(j != 2)
                cout << getGame().getBoardElement(i, j) << " | ";
            else
		        cout << getGame().getBoardElement(i, j);
		}
		cout << "\n";
	}
    cout << "\n";
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
			endl << "Example: A 2 or B 1." << endl;
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

	cout << "Player " << p << "\'s turn:" << endl;

	do
	{	
		getline(cin,coord);
		if (coord.length() == 2)
		{
			coord = coord + coord[1];
		}
		if (coord.length() == 3)
		{
			// prevent trailing space error
			if (coord.at(2) == ' ')
				coord[2] == coord[1];

			// get row
			char row = tolower(coord.at(0));
	
			// get collumn	
			int collumn = coord.at(2) - '0';
	
			// normalize array index
			if (collumn >= 1 && collumn <= 3)
			{
				valid = true;
				x = --collumn;
			}

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

			if (!valid)
				printError(1);
				continue;
		}
		else if (coord == "exit" || coord == "quit")
		{
			cout << "Thank you for playing." << endl;
			exit(0);
		}
		else if (coord == "reset" || coord == "start again" || coord == "clear")
		{
			return 1;
		}
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
