#include <iostream>
#include <string>
using namespace std;

int main()
{
	short int T;
	string J , S;

	cin >> T;
	while(T--)
	{
		int c = 0;
		cin >> J >> S;
		
		for(int i = 0 ; i<J.length() ; i++)
			for(int j = 0 ; j<S.length() ; j++)
			{
				int k = S.find(J[i]);
				if(k == string::npos) continue;
				else
					S[k] = '*',
					c++;
			}
		cout << c << endl;
	}

	return 0;
}