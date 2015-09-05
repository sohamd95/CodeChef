#include <iostream>
#include <cmath>
using namespace std;

typedef long long int lli;

void extended_euclid(lli a, lli b, lli *x,
                     lli *y, lli *d)
/* calculates a * *x + b * *y = gcd(a, b) = *d */
/* Author: Pate Williams (c) 1997 */
{ 
  lli q=0, r=0, x1=0, x2=0, y1=0, y2=0;

  if (b == 0) {
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

int f(lli hi , lli lo = 2)
{
	lli ans = 1;
	for(int i = lo ; i<=hi ; i++)
		ans *= (lli)pow(i,i);
	return ans;
}

int main()
{
	while(true){
	lli N=0 , r=0;
	cin >> N >> r;
	lli numerator = f(N);
	lli denominator = f(r)*f(N-r);
	cout << (f(N)/(f(r)*f(N-r))) << endl;
	cout<< (numerator/denominator) << endl;}
	return 0;
}