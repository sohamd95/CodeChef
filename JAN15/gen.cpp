#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define _N 100000
#define _Q 100

using namespace std;

int main()
{
	fstream fout("in.txt" , ios::trunc|ios::out);

	// fout << 1 << " " << _N << " " << _Q << " ";
	// srand(time(0));
	// int t;

	// for(int i = 0 ; i<_N ; i++)
	// {
	// 	t = (int) 1 + (rand() % (int)(100000 - 1));
	// 	fout << t << " ";
	// }
	
	// int t1 = 0, t2 = 0;
	// srand(time(0));

	// for(int i = 0 ; i<_Q ; i++)
	// {
	// 	do
	// 	{
	// 		t1 = (int) 1 + (rand() % (int)(_N - 1));
	// 		t2 = (int) 1 + (rand() % (int)(_N - 1));
	// 	}
	// 	while(t1 > t2);
	// 	fout << t1 << " " << t2 << " ";
	// }


	fout << "1 10000 1 ";
	for(int i = 0 ; i<9998 ; i++)
		fout << "0 ";
	fout << "99";
	return 0;
}