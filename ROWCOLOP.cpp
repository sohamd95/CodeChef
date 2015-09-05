#include <cstdio>
#include <cstring>
using namespace std;

typedef long int li;

/*inline void inp(li &n)
{
	register li ch = getcx();
	n = 0;

	while(ch >= '0' && ch <= '9')
		n = (n<<3) + (n<<1) + ch - '0', ch = getcx();
}

inline void inp(int &n)
{
	register int ch = getcx();
	n = 0;

	while(ch >= '0' && ch <= '9')
		n = (n<<3) + (n<<1) + ch - '0', ch = getcx();
}*/

int main()

{
	int N , Q;
	char type[7];

	scanf("%i%i",&N,&Q);

	li row[N] , col[N] , RC, X;

	for(int i = 0 ; i< N ; i++)
		row[i] = col[i] = 0;

	while(Q--)
	{
		scanf("%s",type);
		//cin >> RC >> X;
		//inp(RC);inp(X);
		scanf("%ld%ld",&RC,&X);
		
		if(!strcmp(type , "RowAdd"))
			row[RC-1] += X;
		else
			col[RC-1] += X;
	}

	li rMax = 0 , cMax = 0;

	for(int i = 0 ; i<N ; i++)
	{
		if(rMax < row[i])
			rMax = row[i];
		if(cMax < col[i])
			cMax = col[i];
	}
	li ans = cMax + rMax;
	printf("%ld\n", ans);

	return 0;
}