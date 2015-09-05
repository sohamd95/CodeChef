#include <cstdio>

using namespace std;

int B[10000];

bool test(int *B , int &n , int cur , int dec , int rem)
{
	if(rem <= 0)
		return false;

	if(cur == n)
	{
		if(dec && ((double)rem/(double)dec) <= 1)
			return true;
		else return false;
	}

	if(B[cur])
		return test(B , n , cur+1 , dec+1 , rem-B[cur]+1);
	else return test(B , n , cur+1 , dec , rem);
}

int main()
{
	int T , N , t;
	bool flg;

	scanf("%i" , &T);

	while(T--)
	{
		flg = false;
		scanf("%i" , &N);
		
		for(int i = 0 ; i<N ; i++)
		{
			scanf("%i" , &t);
			
			if(t > 100)
				flg = true;
			B[i] = t;
		}

		if(!flg && test(B , N , 0 , 0 , 100))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}