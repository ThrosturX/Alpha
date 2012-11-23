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

        cout << "Player " << player << "\'s turn:" << endl;

		if (getInput(player, getPos()) == 1)
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

string Play::getPos()
{
    string input;
    getline(cin, input);
    return input;
}

int Play::getInput(char p, string coord)
{
	bool valid;
	int x, y;

    while(!valid)
	{
		if (coord.length() == 2)
		{
			coord = coord + coord[1];
		}
		if (coord.length() == 3)
		{
            int column = coord.at(2) - '0';
            char row = tolower(coord.at(0));

			// prevent trailing space error
			if (coord.at(2) == ' ')
				coord[2] == coord[1];
            // normalize array index
			if (column >= 1 && column <= 3 && row >= 'a' && row <= 'c')
			{
                bool addedSymbol = game->addSymbol(p, --column, row-'a');
                if(!addedSymbol)
                    printError(2);
                else
                    valid = true;
			}
            else
                printError(1);
		}
		if (coord == "exit" || coord == "quit")
		{
			cout << "Thank you for playing." << endl;
			exit(0);
		}
		if (coord == "reset" || coord == "start again" || coord == "clear")
        {
            return 1;
        }
        if(!valid)
        {
            coord = getPos();
        }
	}
	return 0;
}

TicTacToe& Play::getGame()
{
	return *game;
}
