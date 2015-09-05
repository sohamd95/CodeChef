#include <cstdio>
#include <climits>
#include <cstring>

using namespace std;

int H[501] , K[501] , dp[501][1001];

inline int min(int a , int b) {
	return (a<b)?a:b;
}

inline void scan(int* x) {
	register char c = getchar_unlocked();
	*x = 0;
	for(; (c<48)||(c>57);c = getchar_unlocked());
	for(; (c>47)&&(c<58);c = getchar_unlocked())
		*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);
}

void calc(int N) {
	for(int i=1 ; i<=N ; i++) {
		for(int j=0 ; j<K[i] ; j++)
			dp[i][j] = dp[i-1][j];
		dp[i][K[i]] = 1;
		for(int j=K[i]+1 ; j<=1000 ; j++)
			dp[i][j] = min(dp[i-1][j] , 1+dp[i][j-K[i]]);
	}
}

int main() {

	int T , N , ans;
	dp[0][0] = 0;
	for(int i = 1 ; i<1001 ; i++)
		dp[0][i] = INT_MAX-1;

	scan(&T);

	while(T--) {
		ans = 0;
		scan(&N);

		for(int i=0 ; i<N ; i++)
			scan(&H[i]);
		for(int i=1 ; i<=N ; i++)
			scan(&K[i]);
		calc(N);

		for(int i = 0 ; i<N ; i++)
			ans += dp[N][2*H[i]];
		printf("%i\n", ans);
	}

	return 0;
}