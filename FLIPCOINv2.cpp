#include <cstdio>
#include <cmath>
#include <cstring>

#define ARRAYSIZ 262144

using namespace std;

/****************************************Behold... FLIPCOIN v2****************************************/

class SegmentTree
{
public:
	SegmentTree(int);
	void update(int , int);	//User-end update function (Calls updateUtil())
	int query(int , int);	//User-end query function (Calls queryUtil())
	void printSTArray();	//Purely for debugging purposes

private:

	void updateUtil(int , int , int , int , int);	//Update with lazy propogation
	int queryUtil(int , int , int , int , int);		//Query

	int st[ARRAYSIZ] , n;
	bool lazy[ARRAYSIZ];
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
		printf("%i,", lazy[i]);
	}
	printf("\n");
}

SegmentTree::SegmentTree(int _n):n(_n)
{
	int p = 2*(int)pow(2,ceil((log(_n)/log(2))));
	memset(st , 0 , sizeof(int)*p);
	memset(lazy , false , p);
}

int SegmentTree::query(int i , int j)
{
	return (queryUtil(1 , 0 , n-1 , i , j));
}

int SegmentTree::queryUtil(int node , int a , int b , int i ,int j)
{
	if(a>b || i>b || j<a)	//Check if segment is valid
		return 0;

	//Check if node is lazy, if so update before proceeding
	if(lazy[node])
	{
		st[node] = (1 + b - a) - st[node];		//Update it
		if(a != b)
		{
			lazy[node<<1] = !lazy[node<<1];			//Mark children as lazy
			lazy[(node<<1)+1] = !lazy[(node<<1)+1];
		}
		lazy[node] = false; //Reset
	}

	if(a >= i && b <= j)	//Current segment range fits into query range
		return st[node];

	return (queryUtil(node<<1 , a , (a+b)>>1 , i , j) + queryUtil((node<<1)+1 , ((a+b)>>1)+1 , b , i , j));
}

void SegmentTree::update(int i , int j)
{
	updateUtil(1 , 0 , n-1 , i ,j);
}

void SegmentTree::updateUtil(int node , int a , int b  , int i , int j)
{
	if(lazy[node]) //This node is already lazy, so it needs to be updated before proceeding
	{
		st[node] = (1 + b - a) - st[node];		//Update it
		if(a != b)
		{
			lazy[node<<1] = !lazy[node<<1];			//Mark children as lazy
			lazy[(node<<1)+1] = !lazy[(node<<1)+1];
		}
		lazy[node] = false; //Reset
	}

	if(a>b || i>b || j<a)	//out of range
		return;

	if(a >= i && b <= j)	//segment range is completly within update range
	{
		//Update Node
		st[node] = (1 + b - a) - st[node];

		//Mark Children as lazy
		if(a != b)
		{
			lazy[node<<1] = !lazy[node<<1];
			lazy[(node<<1)+1] = !lazy[(node<<1)+1];
		}

		return; //No need to go further down the tree
	}

	//Recur for sub-segments
	updateUtil(node<<1 , a , (a+b)>>1 , i , j);
	updateUtil((node<<1)+1 , ((a+b)>>1)+1 , b , i , j);

	if(a != b) st[node] = st[node<<1] + st[(node<<1)+1]; //update current segments
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
			printf("%i\n" , ST.query(A,B));
		else ST.update(A,B);
	}
}