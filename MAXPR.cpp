#include <cstdio>
#include <cstring>

using namespace std;
const int P = (int) 1e9+7;
typedef long long int lli;

inline void scan(int* x) {
	register char c = getchar_unlocked();
	*x = 0;
	for(; (c<48)||(c>57);c = getchar_unlocked());
	for(; (c>47)&&(c<58);c = getchar_unlocked())
		*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);
}

inline void clear(int *A , int siz) {
	memset(A , 0 , sizeof(int)*siz);
}

inline int pow2(int b) {
	if(b == 0) return 1;
	if(b == 1) return 2;
	int t = pow2(b>>1);
	t = (t * 1LL * t) %P;
	if(b%2) return (t<<1);
	return t;
}

inline int add(lli a , lli b) {
	lli res = a+b;
	if(res >= P) res -= P;
	return (int)res;
}

int main() {

	int T , n , min , max;
	int a[200001] , sum[101];
	long long int cur , tmp , ans;

	scan(&T);

	while(T--) {
		scan(&n);
		ans = 0; min = 101; max = -1;

		for (int i = 1 ; i<=n ; i++) {
			scan(&a[i]);
			if(min > a[i]) min = a[i];
			if(max < a[i]) max = a[i];
		}

		for(int diff = min-max ; diff<=max-min ; ++diff) {
			clear(sum , 101);
			cur = 0;

			for(int i = 1 ; i<=n ; ++i) {
				tmp = 0;
				if(a[i]-diff >= min && a[i]-diff <= max)
					tmp = sum[a[i]-diff];
				++tmp;
				cur = add(cur , tmp);
				sum[a[i]] = add(tmp , sum[a[i]]);
				//printf("A: %i\n", cur);
			}
			ans = add(ans , cur);
			ans = add(ans , P-n);
		}
		ans += n;
		ans = (pow2(n) - ans - 1 + P) %P;
		printf("%lli\n", ans);
	}

	return 0;
}