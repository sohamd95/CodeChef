#include <cstdio>
#define M 9001

using namespace std;

typedef unsigned long long int lli;

int main() {
	int T;
	lli N, fib[M];
	fib[1] = 1; fib[2] = 2;
	for(int i = 3; i<=M ; i++)
		fib[i] = fib[i-1] + fib[i-2];
	printf("%llu\n", fib[M]);
	// scanf("%i" , &T);

	// while(T--) {
	// 	scanf("%llu" , &N);

	// }
	return 0;
}