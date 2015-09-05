#include <cstdio>
 
using namespace std;
 
int main()
{
	int T , N , N2 , Bi , tot , zc;
	bool flg;
 
	scanf("%i" , &T);
 
	while(T--)
	{
		zc = tot = 0;
		scanf("%i" , &N);
		N2  = N;
		flg = false;
		
		while(N--)
		{
			scanf("%i" , &Bi);
			if(Bi)
			{
				tot += Bi-1;
			
				if(tot >= 100)
				{
					printf("NO\n");
					flg = true;
					break;
				}
			}
			else zc++;
		}
 
 		if(!flg)
	 	{
	 		if(zc == N2)
	 			printf("NO\n");
	 		else
	 		{
				double test = ((100.0 - tot)/(N2-zc));
		 
				if(test <= 1)
					printf("YES\n");
				else printf("NO\n");
			}
		}
	}
	return 0;
} 