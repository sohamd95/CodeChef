#include <iostream>
#include <map>
using namespace std;

typedef long long int ll;

int main()
{
	std::ios::sync_with_stdio(false);

	map <int , char> paint_position;
	short int T;
	int M , N , y;
	char x;
	const int PRIME = 1000000009;
	ll answer = 1;

	cin >> T;

	while(T--)
	{
		paint_position.clear();
		answer = 1;
		cin >> N >> M;

		for(int i = 0 ; i < M ; i++)
		{
			cin >> x >> y;
			paint_position[y] = x;
		}

		for( map<int,char>::iterator ii=paint_position.begin() ; ii != paint_position.end() ; ++ii)
			if((*ii).second != ((*(++ii)).second))
				answer = (answer * ((*ii).first - (*(--ii)).first)) % PRIME;

		cout << answer << endl;
	}
	return 0;
}
