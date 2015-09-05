#include <iostream>
#include <cmath>

typedef long double lld;
using namespace std;

int main()
{
	lld T , B , LS;
	cin >> T;

	while(T--)
	{
		cin >> B >> LS;
		cout << sqrt(pow(LS,2) - pow(B,2))  << " "  << sqrt(pow(B,2) + pow(LS,2))<< endl;
	}

	return 0;
}