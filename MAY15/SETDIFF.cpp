#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long unsigned int llu;

using namespace std;

const llu P = 1000000007;

llu pow2(const int n) {
	if(n == 0) return 1;
	if(n == 1) return 2;

	llu temp = pow2(n>>1);
	temp = temp %P;

	if(n%2)	//if n is odd
		return ((((temp * temp) %P) * 2) %P);
	return ((temp * temp) %P);
}

struct C{
	bool operator() (const int &a , const int &b)
	{
		return (a>b);
	} 
} cmp;

int main()
{
	int T , N;
	llu ans1 , ans2;
	vector <llu> S;
	vector <llu>::iterator it;

	scanf("%i", &T);

	while(T--)
	{
		ans1 = ans2 = 0;
		scanf("%i" , &N);
		S.resize(N+1);
		it = S.begin();

		for(int i = 1 ; i <= N ; i++)
			scanf("%llu" , &S[i]);

		std::sort(++it , S.end() , cmp);
		for(int i = 1 ; i <= N ; i++) {
			ans1 = (2 * ans1 + A[i]) % P;
  			ans2 = (2 * ans2 + A[N - 1 - i]) % P;
		}
		
		printf("%llu\n" , (ans1+P-ans2) %P);
	}
	return 0;
}