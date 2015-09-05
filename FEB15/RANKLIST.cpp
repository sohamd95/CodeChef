#include <cstdio>

#define lli long long int

using namespace std;

lli calc(lli n , lli s)
{
	lli i = n , t = 0;

	while(i > 0)
	{
		t = (i*(i+1)) >> 1;
		if(t > s) {i--; continue;}
		if(t == s && i == n) break;
		if(t < s && ((n - i) <= (s - t)) && ( (s - t) <= (i*(n - i))) )
			break;
		i--;
	}

	return i;
}

int main()
{
	lli T= 0, m = 0, n = 0, s = 0;

	scanf("%lli" , &T);

	while(T--)
	{
		scanf("%lli%lli" , &n , &s);
		printf("%lli\n", n - calc(n , s));
	}

	return 0;
}