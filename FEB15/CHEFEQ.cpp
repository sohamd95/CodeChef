#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int T , N , Pile[100000];

	scanf("%i" , &T);

	while(T--)
	{
		scanf("%i" , &N);

		for(int i = 0 ; i<N ; i++)
			scanf("%i" , &Pile[i]);

		std::sort(Pile , Pile + N);

		int maxCnt = 1, prev = Pile[0] , si = 0;

		for(int i = 1 ; i<N ; i++)
		{
			if(Pile[i] != prev)
			{
				maxCnt = (maxCnt < i-si)?(i-si):maxCnt;
				si = i;
			}
			prev = Pile[i];
		}
		maxCnt = (maxCnt < N-si)?(N-si):maxCnt;

		printf("%i\n", N-maxCnt);
	}
	return 0;
}