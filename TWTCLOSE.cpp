#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()

{
	short int N,K;
	cin >> N >> K;
	string type;
	bool tweet[N];
	memset(tweet , false , N);
	register int tweet_no;
	int open_count = 0;

	while(K--)
	{
		cin >> type;
		if(type == "CLOSEALL")
			{
				memset(tweet , false , N);
				cout << 0 << endl;
				open_count = 0;
			}
		else
			{
				cin >> tweet_no;
				if(tweet[tweet_no-1])
				 	tweet[tweet_no-1] = false , open_count--;
				else tweet[tweet_no-1] = true , open_count++;
				cout << open_count << endl;
			}
	}
	return 0;
}