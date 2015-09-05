#include <cstdio>
 
using namespace std;
 
#define lli long long int 
#define BIGN 10000002
 
lli fact_mod_m[BIGN];
 
lli F(lli p , lli m)
{
	//If m = 1 n % m will always be 0
	if(m == 1) return 0;
 
	lli p_mod_m = p % m;
 
	//else if m is not 1
	return	( 	(p%2)?	//if p is odd
					(
						( ( ((p+1) >> 1)%m 	* p_mod_m * p_mod_m ) 	% m
					+ 	( (p+1 >= m) ? 0 : fact_mod_m[p+1] ) ) 		% m
					- 	1 + m
					) % m
				:		//else if p is even
					(
						( (	(p >> 1)%m 		* p_mod_m * ((p+1)%m) ) % m
					+ 	( (p+1 >= m) ? 0 : fact_mod_m[p+1] ) ) 		% m
					- 	1 + m
					) % m
			);
}
 
int main()
{
	lli p , sum = 0 , n , m;
 
	scanf("%lli%lli" , &n , &m);
 
	//Calculate factorials (mod m) till 10^7 + 1:
	
	fact_mod_m[1] = 1;
	for(int i = 2 ; i<BIGN ; i++)
		fact_mod_m[i] = (fact_mod_m[i-1] * i%m) % m;
 
	for(int i = 0 ; i<n ; i++)
	{
		scanf("%lli" , &p);
		sum += F(p , m) % m;
	}
 
	printf("%lli\n" , sum % m);
 
	return 0;
} 