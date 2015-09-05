#include <cstdio>
#include <cmath>
#define llu long long unsigned int

int main() {
	
	int T , A , B;
	bool flg;
	llu GCD;

	scanf("%i" , &T);

	while(T--) {
		flg = false;
		scanf("%i%i" , &A , &B);

		for(int i = 2 ; i<=ceil(sqrt(B)) ; i++) {
			if(!(B % i)) {
				if(A % i) {
					printf("No\n");
					flg = true;
					break;
				}
				while(!(B%i))
					B = B/i;
			}
		}
		if(!flg)
			printf("Yes\n");
	}
	return 0;
}