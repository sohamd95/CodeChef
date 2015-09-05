#include <cstring>
#include <iostream>

using namespace std;

#define lli long long int

int main()
{
	lli T , K , Q , q , A[20000] , B[20000];

	cin >> T;

	while(T--)
	{
		cin >> K >> Q;
		memset(A , 0 , sizeof(lli)*K);
		memset(B , 0 , sizeof(lli)*K);

		for(int i = 0 ; i<K ; i++)
			cin >> A[i];
		for(int i = 0 ; i<K ; i++)
			cin >> B[i];
	}

	return 0;
}