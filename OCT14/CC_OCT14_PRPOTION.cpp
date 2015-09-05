#include <iostream>
using namespace std;

typedef long long int ll;

inline ll getmax(ll *tot)
{
	if(tot[0] >= tot[1])
		return (tot[0] >= tot[2])? 0 : 2;
	else
		return (tot[1] >= tot[2])? 1 : 2;
}

int main()
{
	ll T , R , G , B , M , tot[3]={0,0,0};
	ll amt;

	cin >> T;

	while(T--)
	{
		tot[0] = 0; tot[1] = 0; tot[2] = 0;
		cin >> R >> G >> B >> M;

		for(int i = 0 ; i < R ; i++)
		{
			cin >> amt;
			tot[0] = (tot[0] < amt)? amt : tot[0];
		}
		for(int i = 0 ; i < G ; i++)
		{
			cin >> amt;
			tot[1] = (tot[1] < amt)? amt : tot[1];
		}
		for(int i = 0 ; i < B ; i++)
		{
			cin >> amt;
			tot[2] = (tot[2] < amt)? amt : tot[2];
		}

		while(M--)
		{
			switch(getmax(tot))
			{
				case 0:
					tot[0] /= 2;
					break;
				case 1:
					tot[1] /= 2;
					break;
				case 2:
					tot[2] /= 2;
					break;
			}
		}

		cout << tot[getmax(tot)] << endl;
	}

	return 0;
}