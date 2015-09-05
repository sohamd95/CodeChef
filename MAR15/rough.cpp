#include <ctime>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	srand(time(0));
	int n , k , q;
	n = 100000;
	k = 5;
	q = 100000;

	cout << 1 << " ";
	cout << n << " " << k  << " " << q << " ";

	for(int i = 0 ; i<n ; i++)
	{
		cout << rand()%2;
	}
	for(int i = 0 ; i<q ; i++)
	{
		cout << " 1 " << n;
	}

	return 0;
}