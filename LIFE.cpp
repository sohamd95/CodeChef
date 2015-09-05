#include <iostream>
#include <string>
#include <vector>

using namespace std;

string increment_state(string &str)
{
	int len = str.length();
	string next_state = str;

	next_state[0] = (char) ((str[len-1]-'0')^(str[0]-'0')^(str[1]-'0') + '0');

	for(int i = 1 ; i<len-1 ; i++)
	{
		next_state[i] = (char) ((str[i-1]-'0')^(str[i]-'0')^(str[i+1]-'0') + '0');
	}

	next_state[len-1] = (char) ((str[len-2]-'0')^(str[len-1]-'0')^(str[0]-'0') + '0');

	return next_state;
}

int main()
{
	int T , valid;
	string state;
	string prev_state;
	vector <string> V;

	cin >> T;

	while(T--)
	{
		cin >> state;
		prev_state = state;
		V.clear();
		valid = 0;

		for(int i = 0 ; i<4 ; i++)
		{
			switch(i)
			{
				case 0: prev_state[0] = '0'; prev_state[1] = '0'; break;
				case 1: prev_state[0] = '0'; prev_state[1] = '1'; break;
				case 2: prev_state[0] = '1'; prev_state[1] = '0'; break;
				case 3: prev_state[0] = '1'; prev_state[1] = '1'; break;
			}

			for(int j = 2 ; j<state.length() ; j++)
			{
				prev_state[j] = (char) (((prev_state[j-2]-'0')^(prev_state[j-1]-'0')^(state[j-1]-'0')) + '0');
			}

			string next_state = increment_state(prev_state);

			if(next_state == state){V.push_back(prev_state);valid++;}
		}

		switch(valid)
		{
			case 0: cout << "No solution\n"; break;
			case 1: cout << V[0] << endl; break;
			default : cout << "Multiple solutions\n"; break;
		}
	}
}