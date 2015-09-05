#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	
	int T,N,tmp2;
	long long int K,tmp,ans;
	int A[100000];

	scanf("%i" , &T);

	while(T--) {

		ans = 0;
		scanf("%i%lli" , &N , &K);

		for(int i = 0 ; i<N ; i++)
			scanf("%i" , &A[i]);

		if(K > 1e6 * 1LL * N + N)	{printf("1\n");continue;}

		tmp = -1*A[0];
		ans += tmp2;
		tmp += tmp2 * K;
		while(tmp < 0) {tmp += K; ans++;}

		for (int i = 1; i < N ; ++i) {
			if(tmp != 0) tmp--;
			tmp -= A[i];
			tmp2 = abs(tmp)/K;
			ans += tmp2;
			tmp += tmp2 * K;
			if(tmp < 0) while(tmp < 0) { tmp += K; ans++;}
		}
		
		printf("%lli\n", ans);
	}

	return 0;
}