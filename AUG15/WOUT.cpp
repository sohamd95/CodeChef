#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {

	int T, N, H, li, hi;
	int A[1000001];
	long long ans, max, sum;
	scanf("%i" , &T);

	while(T--) {
		sum = 0;
		scanf("%i%i" , &N , &H);
		ans = N * 1LL * H;
		memset(A , 0 , sizeof(A));

		for (int i = 0; i < N; i++) {
			scanf("%i%i" , &li , &hi);
			A[li]++; A[hi+1]--;
		}
		for (int i = 1; i < N; i++)
			A[i] += A[i-1];
		for(int i = 0 ; i<H ; i++)
			sum += A[i];
		max = sum;
		for (int i = H; i < N; i++) {
			sum = (sum - A[i-H] + A[i]);
			if(sum > max) max = sum;
			if(max == ans) break;
		}
		ans -= max;
		printf("%lli\n", ans);
	}
	return 0;
}