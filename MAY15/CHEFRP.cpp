#include <cstdio>
#include <climits>

using namespace std;

int main()
{
	int T , N , Ai , min , ans;
	bool flg;

	scanf("%i" , &T);

	while(T--) 
	{
		flg = false;
		ans = 0;
		min = INT_MAX;

		scanf("%i" , &N);

		for(int i=0 ; i<N ; i++)
		{
			scanf("%i" , &Ai);
			if(Ai < min)
				min = Ai;
			ans += Ai;
			if(Ai == 1)
				flg = true;
		}
		ans -= min;
		ans += 2;

		if(flg) 
			printf("-1\n");
		else printf("%i\n" , ans);
	}

	return 0;
}