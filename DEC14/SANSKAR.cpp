#include <cstdio>
#include <cstring>
#include <cmath>

#define lli long long int
#define BITS 21
#define MAX 2097152
 
using namespace std;

bool dp[9][MAX];

int main()
{
	lli T , N , N2 , K , a , sum , max , max_N , X , V[22];
 
	scanf("%lli" , &T);
 
	while(T--)
	{
		memset(V , 0 , sizeof(lli)*22);
		sum = 0;
		X = 0;

		scanf("%lli%lli" , &N , &K);
		N2 = N;

		max_N = (int) pow(2,N) - 1;
		int l = 0;

		while(N2--)
		{
			scanf("%lli" , &a);
			V[l++] = a;
			sum += a;
		}

		X = sum/K;

		if(sum % K || K > N)
		{
			printf("no\n");
			continue;
		}
		if(!X)
		{
			printf("yes\n");
			continue;
		}

		for(int i = 0 ; i<=K ; i++)
			memset(dp[i] , false , max_N+1);

		dp[0][0] = true;

		lli subSum , C;

		for(int i = 0 ; i<K ; i++)
		{
			for(int j = 0 ; j <= max_N ; j++)
			{
				if(!dp[i][j]) continue;

				subSum = 0;

				for(int k = 0 ; k<N ; k++)
					if(j & (1LL << k))
						subSum += V[k];

				C = subSum - X*i;

				for(int k = 0 ; k<N ; k++)
					if(!(j & (1LL << k)))
					{
						int q = j | (1LL << k);
						if(V[k] + C == X)
							dp[i+1][q] = true;
						else if(V[k] + C < X)
							dp[i][q] = true;
					}
			}
		}
		if(dp[K][max_N])
			printf("yes\n");
		else printf("no\n");
	}

	return 0;
}