#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int T , N = 0 , num = 0 , cnt;
	bool exists[100010];

	scanf("%i" , &T);

	while(T--)
	{
		cnt = 0;
		scanf("%i" , &N);
		memset(exists, false , 100010);

		while(N--)
		{
			scanf("%i" , &num);
			if(!exists[num-1])
				exists[num-1] = true , cnt++;
		}
		
		printf("%i\n", cnt);
	}

	return 0;
}