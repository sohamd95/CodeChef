#include <cstdio>
#include <vector>

using namespace std;

#define lli long long int 
#define BIGN 10000002

vector <int> fact_mod_m(BIGN);

lli F(lli p , lli m)
{
	if(m == 1) return 0;

	lli p_mod_m = p % m;

	return	(
			 	(p % 2)?
					(((((((p + 1) >> 1) % m) * p_mod_m) % m) * p_mod_m) % m)
				:	((((((p >> 1) % m) * p_mod_m) % m) * ((p+1) % m)) % m)
			+	
				(p+1 >= m)?
					(m-1)
				:	((fact_mod_m[p+1] + m - 1) % m)
			) % m;
}

int main()
{
	lli p , sum = 0 , n , m , temp;

	scanf("%lli%lli" , &n , &m);

	//Calculate factorials (mod m) till m:
	
	fact_mod_m[1] = 1;
	for(int i = 2 ; i<m ; i++)
	{
		temp = (fact_mod_m[i-1]*i) % m;
		fact_mod_m[i] = temp;
	}

	for(int i = 0 ; i<n ; i++)
	{
		scanf("%lli" , &p);
		sum += F(p , m);
	}

	printf("%lli\n" , sum % m);
	return 0;
}