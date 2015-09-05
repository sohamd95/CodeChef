#include <iostream>
#include <string>
#include <algorithm>

typedef long double lld;
using namespace std;

struct CompareAlphabetically
{
	bool operator() (const char & c , const char & d)
	{
		return c < d;
	}
}Comp;

bool isLapindrome(string S)
{
	string S2 , S3;

	int len = S.length();

	if(len % 2 == 0)
		{S3 = S.substr(0 , len/2); S2 = S.substr(len/2 , len/2);}
	else {S3 = S.substr(0 , len/2 + 1); S2 = S.substr(len/2 , len/2 + 1);}

	std::sort(S3.begin() , S3.end() , Comp);
	std::sort(S2.begin() , S2.end() , Comp);

	return (S3 == S2);
}


int main()
{
	short int T;
	string S;

	cin >> T;

	while(T--)
	{
		cin >> S;
		if(isLapindrome(S))
			cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}