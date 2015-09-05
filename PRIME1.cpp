#include <cmath>
#include <cstdio>
#include <set>
using namespace std;

int main()
{
	short int T;
	int m , n;

	scanf("%hi",&T);

	int primes[] =
				{	
					2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79,
					83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
					173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263,
					269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367,
					373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
					467, 479, 487, 491, 499, 503, 509, 521, 523, 541
				};
	
	set <int> Primes(primes , primes+100);

	for(int i = 543 ; i<31623 ; i+=2)
	{
		int root = ceil(sqrt(i));
		set <int>::iterator it = Primes.begin();
		bool isPrime = true;

		while(it != Primes.end() && *it <= root)
		{
			if(i % *it == 0) {isPrime = false; break;}
			++it;
		}
		if(isPrime)
			Primes.insert(i);
	}
	while(T--)
	{
		int c = 0;
		scanf("%i%i",&m,&n);
		if(n < 31623)
			for(set<int>::iterator it = Primes.begin() ; it!=Primes.end() ; it++)
				if(*it < m) continue;
				else if(*it > n) break;
				else {printf("%i\n",*it);c++;}

		else
		{
			set<int>::iterator it = Primes.begin();
			int i;
			if(m < 31623)
			{
				while(*it < m)
					++it;
				while(it != Primes.end())
					{printf("%i\n", *it); c++;}
				i = 31623;
			}
			else i = (!(m%2))? m+1 : m;

			for( ; i<=n ; i+=2)
			{
				int root = ceil(sqrt(i));
				set <int>::iterator it = Primes.begin();
				bool isPrime = true;

				while(it!=Primes.end() && *it <= root)
				{
					if(i % *it == 0) {isPrime = false ; break;}
					++it;
				}
				if(isPrime)
					{c++;printf("%i\n", i);}
			}
		}
		printf("*%i*\n",c);
	}
}