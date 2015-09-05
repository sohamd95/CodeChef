#include <iostream>
#include <cstdlib>
#include <ctime>
#define RED 2
#define WHITE 1
#define BLACK 0
using namespace std;

int main()
{
	//Trivial Solution

	short int N , M , K , k;

	cin >> N >> M >> K;

	short int board[N][M];

	//Initializing the game board to white
	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < M ; j++)
			board[i][j] = WHITE;

    k = K;
	while(k--)
	{
		short int i , j;
		cin >> i >> j;
		board[i-1][j-1] = BLACK; //Adding Black Squares
	}

	//chutiyapa...
	short int 	not_painted = M*N - K ,
				i = (rand() % (short int)(N + 1)) , //Generate Random INT b/w 0 and N
				j = (rand() % (short int)(M + 1)) ,	//Generate Random INT b/w 0 and M :P
				mov = (rand() % (short int)(2));	//Thats Right... move (U-D / L-R) is also random.

	// **EVERYTHING** is left to chance...
	int moves = 0;
	short int I[10000] , J[10000] , MOV[10000];

	srand(time(0));

	while(not_painted)
	{
		if(board[i][j] == 0)
		{
			I[moves] = i+1;
			J[moves] = j+1;
			MOV[moves++] = mov;

			if(mov)
			{
				short int k = i;
				while(board[k][j] == 0 && k >= 0)
				{
					board[k--][j] = RED;
					not_painted--;
				}
				k = i+1;
				while(board[k][j] == 0 && k < N)
				{
					board[k++][j] = RED;
					not_painted--;
				}
			}
			else
			{
				short int k = j;
				while(board[i][k] == 0 && k >= 0)
				{
					board[i][k--] = RED;
					not_painted--;
				}
				k = j+1;
				while(board[i][k] == 0 && k < M)
				{
					board[i][k++] = RED;
					not_painted--;
				}
			}
		}

		i = (rand() % (short int)(N));
		j = (rand() % (short int)(M));
		mov = (rand() % (short int)(2));
	}

	//The result:
	cout << moves << "\n";

	for(int m = 0 ; m < moves ; m++)
		cout << I[m] << " " <<  J[m] << " "  <<  MOV[m] << "\n";

	//How can anyone do any worse than this!!?

	return 0;
}
