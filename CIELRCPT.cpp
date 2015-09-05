#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	short int T , i;
	int p , n;
	scanf("%hi" , &T);

	while(T--)
	{
		n = 0;
		i = 11;
		scanf("%i" , &p);
		while(p)
		{
			if(pow(2,i) <= p)
				{p -= (int)pow(2,i); n++;}
			else i--;
		}
		printf("%i\n", n);
	}
	return 0;
}