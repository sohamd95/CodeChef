#include <cstdio>
 
using namespace std;
 
typedef long long int lli;
 
inline lli pow4(int n) {
	if(n == 0) return 1;
	if(n == 1) return 4;
	lli tmp = pow4(n>>1);
	tmp *= tmp;
	if(n %2) return tmp * 4;
	return tmp;
}
 
int main() {
	
	int N , Ai , five;
	lli ans;
 
	scanf("%i" , &N);
 
	while(N--) {
		five = 0;
		scanf("%i" , &Ai);
		ans = Ai;
		while(!(Ai %10)) Ai /= 10;
		while(!(Ai %5)) Ai /= 5, five++;
		ans *= pow4((five+1)>>1);
		printf("%lli\n", ans);
	}
 
	return 0;
} 