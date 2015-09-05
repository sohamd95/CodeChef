#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int nos[5] = {0,0,0,0,0};

	int N;
	char ch;
	short int mrks;

	cin >> N;

	int A[N] , B[N] , C[N] , D[N] , E[N];

	while(N--)
	{
		cin >> ch >> mrks;
		switch(ch - 65)
		{
			case 0:
				A[nos[0]] = mrks;
				break;

			case 1:
				B[nos[1]] = mrks;
				break;

			case 2:
				C[nos[2]] = mrks;
				break;

			case 3:
				D[nos[3]] = mrks;
				break;

			case 4:
				E[nos[4]] = mrks;
				break;
		}
		nos[ch - 65]++;
	}

	std::sort(A , A + nos[0] - 1);
	std::sort(B , B + nos[1] - 1);
	std::sort(C , C + nos[2] - 1);
	std::sort(D , D + nos[3] - 1);
	std::sort(E , E + nos[4] - 1);

	for(int i = 0 ; i < nos[0]-1 ; i++)
	{
		if(A[i+1] == A[i])
	}

	return 0;
}