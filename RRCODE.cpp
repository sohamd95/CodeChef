#include <cstdio>

using namespace std;

int main()
{
	long long int K , ans, N , N2, A[1010];
	int T;
	char op[5];

	scanf("%d",&T);

	while (T--)
	{
		scanf("%lld%lld%lld" , &N , &K , &ans);

		if(!K)
			{printf("%lld\n", ans); continue;}

		int j = 0;
		N2 = N;

		while(N2--)
			scanf("%lld", &A[j++]);

		scanf("%s" , &op);

		switch(op[0])
		{
			case 'X':
				if(!(K % 2)) break;
				else for(int i = 0 ; i<N ; i++)	
					ans = (ans ^ A[i]);
				break;

			case 'A':
				if(!ans) break;
				else for(int i=0 ; i<N ; i++)
						ans = (ans & A[i]);

			default:
				for(int i = 0 ; i<N ; i++)
					ans = (ans | A[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}