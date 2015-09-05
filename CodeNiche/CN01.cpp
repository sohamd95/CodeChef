#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	double X;
	char ch[1000];

	cin >> X >> ch;
	int i = -1;

	while(ch[++i])
	{
		switch(ch[i])
		{
			case 'W':
				X = 2*X + 11;
				break;
			case 'L':
				X = ceil(X/2.0);
				break;
		}
	}
	cout << (int) X;

	return 0;
}