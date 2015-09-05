#include <cstdio>
#define llu long long unsigned int

llu gcd(llu a , llu b) {
	while (a != b) {
		if(a > b)
			a -= b;
		else b -= a;
   }
   return a;
}

bool hasCommonPrimeFactors(llu A , llu B) {
	if(B == 1)
		return true;

	llu d = gcd(A , B);

	if(d == 1)
		return false;

	return hasCommonPrimeFactors(A , B/d);
 }

int main() {
	
	int T;
	llu A , B;

	scanf("%i" , &T);

	while(T--) {
		scanf("%llu%llu" , &A , &B);

		if(hasCommonPrimeFactors(A , B))
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}