#include <iostream>
using namespace std;
typedef long long int ll;

ll n = 0;

ll findNextDinosaurVillage(ll *D , ll ind_d)
{
	ll i = ind_d+1;

	for(i ; i<n ; i++)
		if(D[i] < 0)
			break;

	if(D[i] < 0)
		return i;
	else return -1;
}

ll findNextPeopleVillage(ll *D , ll ind_v)
{
	ll i = ind_v + 1;

	for(i ; i < n ; i++)
		if(D[i] > 0)
			break;

	if(D[i] > 0)
		return i;
	else return -1;
}

int main()
{
	ll T , *D = 0 , ind_d = -1 , ind_v = -1;
	ll cost;

	cin >> T;

	while(T--)
	{
		delete [] D;
		cost = 0;	ind_d = -1;	ind_v = -1;
		cin >> n;
		D = new ll[n];

		for(int i = 0 ; i < n ; i++)
			cin >> D[i];

		//cout<<n<<endl;

		ind_d = findNextDinosaurVillage(D , ind_d);
		ind_v = findNextPeopleVillage(D , ind_v);
		//cout<<endl<<ind_d<<" ** "<<ind_v<<endl;

		while(ind_d != -1 && ind_v != -1)
		{
			//cout<<endl<<ind_d<<" !! "<<ind_v<<endl;

			if(abs(D[ind_d]) > abs(D[ind_v]))
			{
				cost += abs(ind_d - ind_v)*(D[ind_v]);
				D[ind_d] += D[ind_v];
				ind_v = findNextPeopleVillage(D , ind_v);
			}
			else if(abs(D[ind_d]) < abs(D[ind_v]))
			{
				cost += abs((ind_d - ind_v))*abs(D[ind_d]);
				D[ind_v] += D[ind_d];
				ind_d = findNextDinosaurVillage(D , ind_d);
			}
			else
			{
				cost += abs(ind_d - ind_v)*(D[ind_v]);
				D[ind_v] = 0; D[ind_d] = 0;
				ind_v = findNextPeopleVillage(D , ind_v);
				ind_d = findNextDinosaurVillage(D , ind_d);
			}
		}

		cout << cost << endl;
	}
	return 0;
}