#include <cstdio>
#include <cmath>

using namespace std;
typedef long long lli;

lli Util(lli lo , lli hi , lli M = 1)
{
	lli a = 1;
	for(lli i = lo ; i <= hi ; i++)
		a = ( (a%M) * (((lli)pow(i , i))%M) ) %M;

	return a;
}
void extended_euclid(lli a, lli b, lli *x, lli *y, lli *d)
{ 
  lli q, r, x1, x2, y1, y2;

  if (b == 0)
  {
    *d = a, *x = 1, *y = 0;
    return;
  }
  x2 = 1, x1 = 0, y2 = 0, y1 = 1;
  while (b > 0) {
    q = a / b, r = a - q * b;
    *x = x2 - q * x1, *y = y2 - q * y1;
    a = b, b = r;
    x2 = x1, x1 = *x, y2 = y1, y1 = *y;
  }
  *d = a, *x = x2, *y = y2;
}

lli compute(lli N , lli r, lli M)
{

	//lli f = ( Util(2,N) / (Util(2,r)*Util(2,N-r)) );

	lli numerator = Util(r+1 , N,M);
	lli denominator = Util(2 , N-r,M);
	//lli numerator = Util(2,N);
	//lli denominator = (Util(2,r)*Util(2,N-r));
	lli y=0 , d=0 , mmi=0;

	extended_euclid(denominator , M , &mmi , &y , &d);

	lli f2 = mmi*numerator;
	//lli f = (numerator % M) * (mmi % M);
	//printf("*%lli*%lli\n", f , f2);
	return ((numerator % M) * (mmi % M)) % M;
}

int main()
{
	lli T=0, N=0 , M=0 , Q=0 , r=0 , ans=0;
	scanf("%lli" , &T);

	while(T--)
	{
		scanf("%lli%lli%lli" , &N , &M , &Q);

		while(Q--)
		{
			scanf("%lli" , &r);
			ans = compute(N , r , M);
			printf("%lli\n", ans);
		}
	}
	return 0;
}