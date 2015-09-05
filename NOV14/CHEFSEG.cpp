#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int T;
	long double K , nearest_pow2, X, ans = 0;

	scanf("%i" , &T);

	while(T--)
	{
		scanf("%Lf%Lf" , &X , &K);
		
		nearest_pow2 = pow(2,floor(log2(K)));
		
		ans = ((X/(2*nearest_pow2)) * (2*(K - nearest_pow2)+1));
		
		printf("%Lf\n", ans);
	}
}