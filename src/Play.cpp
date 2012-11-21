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

void Play::getInput()
{
    for(int i = 1;i<=2;i++)
    {
        while(!(getGame().fullBoard()))
        {
            char a;
            int y;
            cout << "Player" << i <<"'s Turn " << endl;
            cout << "please enter the column name (A,B,C) and the row number of where you'd like to play \n";
            cout << "For example, A 2 or B 0" << endl;
            cin >> a,y;
            while(!correctInput(a,y) || exists(a-65,y))
            {
                if(!correctInput(a,y))
                {
                    cout << "Please enter your input in the right format. Example A 2 or B 0" << endl;
                    cin >> a >> y;
                }

                if(exists(a-65,y) && correctInput(a,y))
                {
                    cout << "Invalid play, please try again" << endl;
                    cin >> a >> y;
                }
            }

        getGame().addSymbol('X',a-65,y); //a - 65 because of ASCII
        }
    }

}

TicTacToe& Play::getGame()
{
	return *game;
}

bool Play::correctInput(char a,int y)
{
    if(a != ('A','B','C') && y != (0,1,2))
        return false;
    else
        return true;
}

bool Play::exists(int x,int y)
{
    if(x > 2 || x < 0 || y > 2 || y < 0)
        return false;

    else if(getGame().getBoard()[x][y] != ' ')
        return false;

    else
        return true;
}
