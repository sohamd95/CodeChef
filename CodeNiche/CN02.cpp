#include <string>
#include <iostream>
#include <set>

using namespace std;

int calc(int n)
{
	return ((n*(n-1))/2);
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	string str;
	int T , l , sum;
	set <string> Suffix;

	cin >> T;

	while(T--)
	{
		cin >> str;
		l = str.length();
		sum = 0;

		for(int i = 0 ; i<l ; i++)
			Suffix.insert(str.substr(i , l-i));
		
		cout << (*Suffix.begin())[0];

		set<string>::iterator it1 , it2;
		it1 = it2 = Suffix.begin();

		while(it2 != Suffix.end())
		{
			++it2;
			int j = 0;
			while((*it1)[j] == (*it2)[j++]);
			sum += j;
			++it1;
		}

		cout << calc(l)-sum << endl;
	}
	return 0;
}