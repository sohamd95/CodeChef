#include <cstdio>
#include <cmath>
#include <cstring>

#define ARRAYSIZ 262144

using namespace std;

class SegmentTree
{
public:
	SegmentTree(int);
	void update(int , int);
	void updateUtil(int , int , int , int , int);
	void query(int , int);
	int queryUtil(int , int , int , int , int);
	void printSTArray();

	int st[ARRAYSIZ] , lazy[ARRAYSIZ] , n;
};

void SegmentTree::printSTArray()
{
	printf("st:\t");
	for(int i = 1 ; i<=2*pow(2,ceil((log(n)/log(2)))) ; i++)
	{
		printf("%i,", st[i]);
	}
	printf("\nlazy:\t");
	for(int i = 1 ; i<=2*pow(2,ceil((log(n)/log(2)))) ; i++)
	{
		if(lazy[i] == -1)
			printf("*,");
		else printf("%i,", lazy[i]);
	}
	printf("\n");
}

SegmentTree::SegmentTree(int _n):n(_n)
{
	int p = 2*(int)pow(2,ceil((log(_n)/log(2))));
	memset(st , 0 , sizeof(int)*ARRAYSIZ);
	memset(lazy , -1 , sizeof(int)*ARRAYSIZ);
}

void SegmentTree::query(int i , int j)
{
	printf("%i\n", queryUtil(1 , 0 , n-1 , i , j));
}

int SegmentTree::queryUtil(int node , int a , int b , int i ,int j)
{
	if(a > b || i>b || j<a) return 0;
	printf("qIN node: %i a: %i b: %i\n", node , a , b);

	if(lazy[node] != -1)
	{ // This node needs to be updated
		printf(" lazy\n");
		st[node] = lazy[node]; // Update it
 
		if(a != b)
		{
			if(lazy[node<<1] == -1)
				lazy[node<<1] = 1+((a+b)/2 - a) - st[2*node];
			else lazy[node<<1] = 1+((a+b)/2 - a) - lazy[2*node];

			if(lazy[(node<<1) + 1] == -1)
				lazy[node*2+1] = 1 + (b-1-((a+b)/2)) - st[2*node + 1];
			else lazy[node*2 + 1] = 1 + (b-1-((a+b)/2)) - lazy[2*node + 1];
		}
 
		lazy[node] = -1; // Reset it
	}

	if(i <= a && j >= b)
		return st[node];

	return (queryUtil(2*node , a , (a+b)/2 , i , j) + queryUtil(2*node + 1 , ((a+b)/2)+1 , b , i , j));

}

void SegmentTree::update(int i , int j)
{
	printf("up\n");
	updateUtil(1 , 0 , n-1 , i ,j);
}

void SegmentTree::updateUtil(int node , int a , int b  , int i , int j)
{
	printf("uIN node: %i a: %i b: %i\n", node , a , b);
	if(lazy[node] != -1) //node needs updation
	{
		//update it:
		printf(" lazy\n");
		st[node] = lazy[node];

		//Mark children as lazy:
		if(a != b)
		{			
			if(lazy[node<<1] == -1)
				lazy[node<<1] = 1+((a+b)/2 - a) - st[2*node];
			else lazy[node<<1] = 1+((a+b)/2 - a) - lazy[2*node];

			if(lazy[(node<<1) + 1] == -1)
				lazy[node*2+1] = 1 + (b-1-((a+b)/2)) - st[2*node + 1];
			else lazy[node*2 + 1] = 1 + (b-1-((a+b)/2)) - lazy[2*node + 1];
		}

		//Reset:
		lazy[node] = -1;
	}

	if(a>b || i>b || j<a) 	//out of range
	{
		printf(" ret\n");
		return;
	}

	if(a >= i && b <= j)	//current segment is completely in range
	{
		printf("in: %i , %i\n" , node , (1+(b-a)) - st[node]);
		st[node] = (1+(b-a)) - st[node];

		if(a != b)	//Mark children as lazy
		{
			printf("lazymrk\n");
			if(lazy[node<<1] == -1)
				lazy[node<<1] = 1+((a+b)/2 - a) - st[2*node];
			else lazy[node<<1] = 1+((a+b)/2 - a) - lazy[2*node];

			if(lazy[(node<<1) + 1] == -1)
				lazy[node*2+1] = 1 + (b-1-((a+b)/2)) - st[2*node + 1];
			else lazy[node*2 + 1] = 1 + (b-1-((a+b)/2)) - lazy[2*node + 1];
		}
		return;
	}

	if(a == b) return;

	updateUtil(node<<1 , a , (a+b)>>1 , i , j);
	updateUtil((node<<1)+1 , 1+((a+b)>>1) , b , i , j);

	st[node] = st[node<<1] + st[(node<<1) + 1];
}

int main()
{
	int N , Q , typ , A , B;
	
	scanf("%i%i" , &N , &Q);
	SegmentTree ST(N);

	while(Q--)
	{
		scanf("%i%i%i" , &typ , &A , &B);
		
		if(typ)
			ST.query(A,B);
		else ST.update(A,B);

		ST.printSTArray();
	}
}