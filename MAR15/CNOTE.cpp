#include <cstdio>

using namespace std;

int main()
{
	int N , T;
	short int X , Y , K , pages_needed , Pi , Ci;
	bool flg;

	scanf("%i" , &T);

	while(T--)
	{
		flg = false;
		scanf("%hi%hi%hi%i" , &X , &Y , &K , &N);
		pages_needed = X - Y;

		while(N--)
		{
			scanf("%hi%hi" , &Pi , &Ci);
			if(Pi >= pages_needed && Ci <= K)
				flg = true;
		}

		if(flg)
			printf("LuckyChef\n");
		else printf("UnluckyChef\n");
	}

	return 0;
}