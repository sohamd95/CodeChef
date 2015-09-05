#include <cstdio>
#include <climits>

using namespace std;

inline int min(int a , int b)
{
	return ((a < b) ? a : b);
}

int main()
{
	int N, dp[100][100] , colour[100][100];

	while(scanf("%i" , &N) != EOF)
	{

		for(int i = 0 ; i<N ; i++)
		{
			scanf("%i" , &colour[i][i]);
			dp[i][i] = 0;
		}

		if(N == 1)
		{
			printf("0\n");
			continue;
		}

		for(int len = 2 ; len<=N ; len++)
		{
			for(int i = 0 ; i<=N-len ; i++)
			{
				int j = i+len-1;
				dp[i][j] = INT_MAX;

				for(int k = i ; k<j ; k++)
				{
					dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k+1][j] + (colour[i][k]*colour[k+1][j]));
					colour[i][j] = (colour[i][k] + colour[k+1][j]) % 100;
				}
			}
		}

		printf("%i\n", dp[0][N-1]);
	}

	return 0;
}