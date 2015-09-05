#include <iostream>
#include <cstdio>
#define getcx getchar_unlocked
typedef long long int ll;

using namespace std;

inline void inp(ll &n)
{
	n = 0;
    int ch = getcx();

    while(ch >= '0' && ch <= '9')
        n = (n<<3)+(n<<1) + ch-'0' //Equivalent to n = n*10 + ch-48;
    	,ch = getcx();
}

int main()
{
	ll T , N , ans;
	inp(T);

	while(T--)
	{
		inp(N);
		ans = N*(1.5 + 0.5*N);
		printf("%lld\n", ans);
	}
}