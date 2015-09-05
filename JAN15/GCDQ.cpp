#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int A[262144];
int B[100001];

int gcd(int a , int b)
{
	 int c;
	 while ( a != 0 )
	 {
	 	c = a;
	 	a = b % a;
	 	b = c;
	 }
	 return b;
}

int queryUtil(int node , int a , int b , int i , int j)
{
	if(a > b || i>b || j<a) return 0;

	if(i<=a && j>=b)
		return A[node];

	return gcd(queryUtil(2*node , a , (a+b)/2 , i , j) , queryUtil(2*node + 1 , ((a+b)/2)+1 , b , i , j));
}

int query(int N, int qs , int qe)
{
	return queryUtil(1 , 1 , N , qs , qe);
}

void buildST(int * B , int node , int ss , int se)
{
	if(ss > se)
		return;

	if(ss == se)
	{
		A[node] = B[ss];
		return;
	}

	buildST(B , 2*node , ss , (ss+se)/2);
	buildST(B , 2*node + 1, ((ss+se)/2) + 1 , se);

	A[node] = gcd(A[2*node] , A[2*node + 1]);
}

void printSTArray(int n)
{
	printf("st: ");
	for(int i = 1 ; i<2*pow(2,ceil((log(n)/log(2)))) ; i++)
	{
		printf("%i,", A[i]);
	}
	printf("\n");
}

int main()
{
	int T , N , Q , qs, qe , w;

	scanf("%i" , &T);

	while(T--)
	{
		scanf("%i%i" , &N , &Q);
		w = 2*(int)pow(2,ceil(log(N)/log(2)));
		memset(A , 0 , sizeof(int)*w);

		for(int i = 1 ; i <= N ; i++)
			scanf("%i" , &B[i]);

		buildST(B , 1 , 1 , N);
		//printSTArray(N);

		while(Q--)
		{
			scanf("%i%i" , &qs , &qe);
			int ans = gcd(query(N , 1 , qs-1) , query(N , qe+1 , N));
			printf("%i\n", ans);
		}
	}

	return 0;
}