#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

long long A[100001] , B[100001];

int main()
{
	long long max_p , T, N , K , temp , t2;

	scanf("%lli" , &T);

	while(T--)
	{
		max_p  = 0;
		scanf("%lli%lli" , &N , &K);
		memset(A , 0 , sizeof(long long)*N);
		memset(B , 0 , sizeof(long long)*N);

		for(int i = 0 ; i<N ; i++)
		{
			scanf("%lli" , &temp);
			A[i] = K/temp;
		}

		for(int i = 0 ; i<N ; i++)
			scanf("%lli" , &B[i]);

		for(int i = 0 ; i<N; i++)
		{
			t2 = A[i] * B[i];
			if(max_p < t2)
				max_p = t2;
		}
		printf("%lli\n", max_p);
	}

	return 0;
}