#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int T , N , t;
	char A[1000];
	int dig[10];

	scanf("%i" , &T);

	while(T--)
	{
		srand(time(0));
		memset(dig , 0 , sizeof(int)*10);
		scanf("%s%i" , A, &N);
		while(N--)
			scanf("%i" , &t);
		int len = strlen(A) , r;

		for(int i = 0 ; i <strlen(A) ; i++)
			dig[A[i]-'0']++;
	}

	return 0;
}