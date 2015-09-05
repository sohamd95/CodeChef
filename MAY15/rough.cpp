#include <iostream>
#include <climits>
#include <cstdio>
#include <vector>
#define llu long long unsigned int
#define PRIME 1000000007
#define P 1000000000

using namespace std;

long long C[4001][2001];

llu pow2(int n) {
	if(n == 0) return 1;
	if(n == 1) return 2;

	llu temp = pow2(n>>1);
	temp = temp % PRIME;

	if(n%2)
		return ((temp * temp) << 1) %PRIME;
	return (temp * temp) %PRIME;
}

int main() {
 
    for (int i=0; i<=4000; i++)
    {
        for (int k=0; k<=2000 && k<=i; k++)
            if (k==0 || k==i)
                C[i][k] = 1;
            else
                C[i][k] = (C[i-1][k-1] + C[i-1][k]) %P;
    }

	//cout << (llu)((1-3+PRIME) %PRIME);
	unsigned long long int a,b;
	double d;
	a = b = 1000000000000000000ULL ;
	d = (double)a * b;

	//cout << d;
	// cout <<23423423<< "YO!";
	// cout << 53465436563LL %PRIME << std::endl;
	// cout << pow2(1000) << std::endl;

	// cout << "1 1000 ";
	// for(int i = 0 ; i<1000 ; i++) {
	// 	cout << i << " ";
	// }
	return 0;
}