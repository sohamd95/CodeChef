#include <cstdio>
#define MAX 87

using namespace std;

typedef unsigned long long int lli;

int main() {
	int T, ans;
	lli N, fib[MAX+1];
	fib[1] = 1; fib[2] = 2;
	for(int i = 3; i<=MAX ; i++)
		fib[i] = fib[i-1] + fib[i-2];

	scanf("%i" , &T);

	while(T--) {
		scanf("%llu" , &N);
		ans = 1;
		while(fib[ans] < N) ans++;
		if(N != fib[ans]) ans--;
		printf("%i\n", ans);
	}
	return 0;
}