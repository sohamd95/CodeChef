#include <cstdio>
#include <stack>
#include <map>

using namespace std;

int A[100001], freq[100001], lessThan[100001], greaterThan[100001];

int main() {
	
	int N, K, maxAi = 0, maxAj;
	long long int ans = 0;
	stack<int> S, S2;

	scanf("%i%i" , &N , &K);

	for(int i = 1 ; i <= N ; i++) {
		scanf("%i" , &A[i]);
		freq[i] = N-i;
		if(A[i] > maxAi) maxAi = A[i];
	}
	maxAj = maxAi - K;

	for(int i = N ; i>=1 ; i--) {
		while(!S.empty() && (A[i] < A[S.top()])) S.pop();
		if(S.empty()) lessThan[i] = N+1;
		else lessThan[i] = S.top();
 
		while(!S2.empty() && (A[i] >= A[S2.top()])) S2.pop();
		if(S2.empty()) greaterThan[i] = N+1;
		else greaterThan[i] = S2.top();

		S.push(i);
		S2.push(i);
	}

	for(int i = N-1 ; i>=1 ; i--) {
		freq[i] -= (N-i-1 - freq[i+1]);
		if(A[i] == K) {
			if(lessThan[i] > i+freq[i]) freq[i] = 0;
			else if(greaterThan[i] <= i+freq[i])
				freq[i] -= (i-greaterThan[i]+freq[i+1]+2);
		}
		else if(maxAj > 0 && A[i] > K<<1) {
			for(int j = lessThan[i] ; j<=i+freq[i] ; j++)
				if(A[j] > K && A[j] <= maxAj && A[i] %A[j] == K) {
					freq[i] -= (i-j+freq[i+1]+2);
					break;
				}
		}
	}

	for(int i = 1 ; i<=N ; ++i)
		ans += freq[i];
	ans += N;
	
	// for(int i = 1 ; i<=N ; i++) {
	// 	printf("%i," , freq[i]);
	// } printf("\n");

	printf("%lli\n", ans);

	return 0;
}