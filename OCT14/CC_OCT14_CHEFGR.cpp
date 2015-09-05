#include <iostream>
using namespace std;

int main()
{
	int M , N , T , *h_init , h_max = 0 , blks_req = 0;

	cin >> T;

	while(T--)
	{
		delete [] h_init;
		h_max = 0;
		blks_req = 0;
		cin >> M >> N;

		h_init = new int [M];

		for (int i = 0 ; i < M ; i++)
		{
			cin >> h_init[i];
			if(h_init[i] > h_max)
				h_max = h_init[i];
		}	

		for (int i = 0; i < M; i++)
			blks_req += (h_max - h_init[i]);

		if(blks_req == N)
			cout << "Yes" ;
		else if(blks_req > N)
			cout << "No" ;
		else if((N - blks_req) % M == 0)
			cout << "Yes" ;
		else cout << "No" ;

		cout << endl;
	}

	return 0;
}