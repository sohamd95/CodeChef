#include <cstdio>

inline bool isPowerOfTwo(int n) {
  return !(n & (n - 1));
}

using namespace std;

int main() {

	int T, A, B, ans;
	scanf("%i" , &T);

	while(T--) {
		ans = 0;
		scanf("%i%i" , &A , &B);
		while(!isPowerOfTwo(A)) A=(A>>1), ans++;
		if(B < A) while(A != B) A=(A>>1), ans++;
		else while(A != B) A=(A<<1), ans++;
		printf("%i\n", ans);
	}
	return 0;
}