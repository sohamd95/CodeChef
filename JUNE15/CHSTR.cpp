#include <iostream>
#include <cstring>
 
using namespace std;
 
int Z[5001] , tmp[5001] , cnt[5001];
int ans[5001] , fact[5001] , ifact[5001];
const int P = (int) 1e9+7;
 
inline void clear(int *A , int siz) {
	memset(A  , 0 , siz*sizeof(int));
}

//Fast Input (Yes... It is required for this problem ;) )
inline void scan(int* x) {
	register char c = getchar_unlocked();
	*x = 0;
	for(; (c<48)||(c>57);c = getchar_unlocked());
	for(; (c>47)&&(c<58);c = getchar_unlocked())
		*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);
}

//Calculates C(n,k) %P
inline int C(int n , int k) {
	int res = fact[n];
    res = (res * 1ll * ifact[k]) % P;
    res = (res * 1ll * ifact[n-k]) % P;
    return res;
}
 
//Fast exponentiation (mod P)
int pow(int a , int b) {
	if(b == 0) return 1;
	if(b == 1) return a %P;
 
	int t = pow(a , b/2);
	t = (t * 1ll * t) %P;
 
	if(b%2)	return (t * 1ll * a) %P;
	return t;
}

//Function to calculate Z-function of a string
void calcZ(char s[]) {
 
	int n = strlen(s);
	int L, R, k;
	clear(Z , n);
	Z[0] = strlen(s);
	L = R = 0;
 
	for(int i = 1 ; i<n ; i++) {
		if (i > R) {
			L = R = i;
			while (R < n && s[R-L] == s[R]) R++;
			Z[i] = R-L;
			R--;
		} else {
			k = i-L;
			if (Z[k] < R-i+1) Z[i] = Z[k];
			else {
				L=i;
				while (R < n && s[R-L] == s[R]) R++;
				Z[i] = R-L;
				R--;
			}
		}	
	}
}
 
//Precomputation
void precomp(char str[]) {
 
	int n = strlen(str);
	char suffix[5001];
	clear(ans , n+1);
	clear(cnt , n+1);
 
	for(int i = 0 ; i<n ; i++) {
		
		strncpy(suffix , str+i , n-i+1);
		calcZ(suffix);
		clear(tmp , n+1);
 
		for(int j = 0 ; j<n-i ; j++)
			tmp[Z[j]]++;
		for(int k = n-1 ; k>=1 ; k--)
			tmp[k] += tmp[k+1];
		for(int j = 1 ; j<=n ; j++)
			cnt[tmp[j]]++;
	}
 
	for(int i = 1 ; i<=n-1 ; i++)
		cnt[i] = cnt[i] - cnt[i+1];
 
	for(int i = 1 ; i<=n ; i++) {
		for(int j = i ; j<=n ; j++)
			ans[i] =  (ans[i] + (int)((C(j , i) * 1ll * cnt[j]) %P)) %P;
	}
}
 
int main() {
 
	int T , N , Q , K;
	char str[5001];
	fact[0] = ifact[0] = 1;
 
	scan(&T);
 
	while(T--) {
 
 		scan(&N);
 		scan(&Q);
		scanf("%s" , str);

		for(int i = 1 ; i<=N ; i++) {
			fact[i] = (fact[i-1] * 1ll * i) %P;
			//MMI calculated using Fermat's Theorm (when P is prime);
			ifact[i] = pow(fact[i] , P-2);
		}
 
		precomp(str);
 
		while(Q--) {
			scan(&K);
			if(K <= N)
				printf("%i\n", ans[K]);
			else printf("0\n");
		}
	}
	return 0;
} 