#include <cstdio>
using namespace std;
#define getcx getchar_unlocked

typedef unsigned long long int ulli;

inline void inp(int &n)
{
	register int ch = getcx();
	n = 0;

	while(ch >= '0' && ch <= '9')
		n = (n << 3) + (n << 1) + ch - '0' , ch = getcx();
}

inline void inp(ulli &n)
{
	register int ch = getcx();
	n = 0;

	while(ch >= '0' && ch <= '9')
		n = (n << 3) + (n << 1) + ch - '0' , ch = getcx();
}

int main()

{
	int T;
	inp(T);
	unsigned long long int N , K;

	while(T--)
	{
		inp(N); inp(K);
		if(N == 0) {printf("0 0\n"); continue;}
		if(K == 0) {printf("0 %llu\n" , N); continue;}
		ulli a1 = (N / K);
		ulli a2 = (N % K);
		printf("%llu %llu\n" , a1 , a2);
	}
	return 0;
}