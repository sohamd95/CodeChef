#include <iostream>
#include <string>
using namespace std;

#define PRIME 10000009

int main()

{
	int T;
	string str;
	int ans = 1;

	cin >> T;

	while(T--)
	{
		ans = 1;
		cin >> str;
		int len , len2;
		len = len2 = str.length();
		len--;
		for(int i = 0 ; i<((len2)/2) ; i++)
			{
				//cout << i << " " << len << endl;
				if(str[i] == '?' && str[len] == '?')
					ans = (ans * 26) % PRIME;
				if((str[i]!='?' && str[len]!='?') && (str[i] != str[len]))
					{ans = 0; break;}
				len--;
			}
		if((len2%2) && (str[len2/2] == '?')) ans *= 26;
		cout << ans << endl;
	}

	return 0;
}