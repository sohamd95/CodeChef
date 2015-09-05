#include <cstdio>
#include <cmath>

#define ulli unsigned long long int

using namespace std;

inline int min(int a , int b)
{
	return ((a<b)? a : b);
}

int main()
{
	int T , S , C , K , Y;

	scanf("%i" , &T);

	while(T--)
	{
		scanf("%i%i%i" , &S , &C , &K);
		Y = min(C , S-K+1);

		if(S == 0 && K == 1)
		{
			printf("%llu\n", ((1ull << (C + 1)) - 2) );
			continue;
		}
		else if(S == 0 || S < K)
		{
			printf("0\n");
			continue;
		}

		printf("%llu\n",

				(S <= C)?
						(
						(K == 1)?
							((1ull << (C + 1)) + 1)
							:((1ull << (S-K+2)) + 1)
						)
						:
						(
						(S-K <= Y)?
							((1ull << (Y + 1)) + 1)
							:((1ull << (S-K+1)) + 1)
						)

				);
	}

	return 0;
}