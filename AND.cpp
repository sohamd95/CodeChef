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
        n = (n << 3) + (n << 1) + ch - '0' //Equivalent to n = n*10 + ch-48;
    	,ch = getcx();
}

int main()
{
	ll N , sum = 0;
	inp(N);

	ll numbers[N];

	for(int i = 0 ; i < N ; i++)
		inp(numbers[i]);

	for(int i = 0 ; i<N-1 ; i++)
		for(int j = i+1 ; j<N ; j++)
			sum += numbers[i] & numbers[j];

	printf("%lld",sum);

	return 0;
}