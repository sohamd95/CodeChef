#include <cstdio>
#include <cmath>

// #define debugQ
// #define intenseDebugQ
// #define debugU
// #define intenseDebugU

using namespace std;

const int P = (int) 1e9+7;
const int ARRAYSIZ = 262145;

class SegmentTree
{
public:
	SegmentTree(int , int*);
	void update(int , int , int , int);	//User-end update function
	int query(int , int);				//User-end query function
	void printSTArray();				//Purely for debugging purposes

private:

	struct node
	{
		node():sum(0),mul(1),add(0),flg(false){}
		int sum, mul, add;
		bool flg;
	};

	void constructUtil(int , int , int , int*&);
	void updateUtil(int , int , int , int , int , int , int);	//Update with lazy propogation
	int queryUtil(int , int , int , int , int);		//Query
	void applyUpdates(int , int);
	void pushDown(int , int , int);
	void reset(int);

	node st[ARRAYSIZ];
	int n , used;
};

void SegmentTree::printSTArray()
{
	printf("sum: [");
	for(int i = 1 ; i<=used ; i++)
		printf("%i,", st[i].sum);
	printf("]\n");
	
	printf("mul: [");
	for(int i = 1 ; i<=used ; i++)
		printf("%i,", st[i].mul);
	printf("]\n");
	
	printf("add: [");
	for(int i = 1 ; i<=used ; i++)
		printf("%i,", st[i].add);
	printf("]\n");
}

SegmentTree::SegmentTree(int _n , int *A):n(_n)
{
	used = 2*(int)pow(2,ceil((log(_n)/log(2))));
	constructUtil(1 , 1 , n , A);
}

void SegmentTree::constructUtil(int node , int a , int b , int *&A)
{
	int lchild = (node<<1), rchild = lchild+1, mid = (a+b)>>1;
	if(a == b)
	{
		st[node].sum = A[a];
		return;
	}
	constructUtil(lchild , a , mid , A);
	constructUtil(rchild , mid+1 , b , A);
	st[node].sum = (st[lchild].sum + st[rchild].sum) %P;
}

void SegmentTree::applyUpdates(int index , int size)
{
	st[index].sum = ((int)((st[index].add * 1LL * size) %P) + (int)((st[index].mul * 1LL * st[index].sum) %P)) %P;
}

void SegmentTree::pushDown(int index , int ss , int se)
{
	if(ss != se) //Pushable?
	{
		#ifdef intenseDebugU
				printf("pushDown called from node %i\n", index);
		#endif
		int lchild = (index<<1), rchild = lchild+1, mid = ((ss+se)>>1);
		bool flg = false;

		if(st[index].flg) {
			reset(lchild);
			reset(rchild);
			st[lchild].sum = st[rchild].sum = 0;
			st[lchild].flg = st[rchild].flg = true;
			st[index].flg = false;
			#ifdef intenseDebugU
				printf("reset\n", index);
			#endif
		}

		if(st[index].mul != 1) {
			st[lchild].mul = (st[index].mul * 1LL * st[lchild].mul) %P;
			st[rchild].mul = (st[index].mul * 1LL * st[rchild].mul) %P;
			st[lchild].add = (st[index].mul * 1LL * st[lchild].add) %P;
			st[rchild].add = (st[index].mul * 1LL * st[rchild].add) %P;
			#ifdef intenseDebugU
				printf("pushDown MUL\nSet st[%i].mul = %i\nSet st[%i].mul = %i\n", lchild, st[lchild].mul, rchild, st[rchild].mul);
			#endif
		}

		if(st[index].add) {
			st[lchild].add = (st[index].add + st[lchild].add) %P;
			st[rchild].add = (st[index].add + st[rchild].add) %P;
			#ifdef intenseDebugU
				printf("pushDown ADD\nSet st[%i].add = %i\nSet st[%i].add = %i\n", lchild , st[lchild].add , rchild, st[rchild].add);
			#endif
		}
	}
}

void SegmentTree::reset(int index)
{
	st[index].mul = 1;
	st[index].add = 0;
	st[index].flg = false;
}

int SegmentTree::query(int i , int j)
{
	#ifdef debugQ
		printf("---------------------------------------\n");
	#endif
	int t = queryUtil(1 , 1 , n , i , j);
	#ifdef debugQ
		printSTArray();
	#endif
	return t;
}

int SegmentTree::queryUtil(int index , int ss , int se , int qs ,int qe)
{
	#ifdef intenseDebugQ
		printf("Query @ node %i S.R: [%i,%i] Q.R: [%i,%i]\n", index , ss , se , qs , qe);
	#endif

	int lchild = (index<<1), rchild = lchild+1, mid = ((ss+se)>>1);

	applyUpdates(index, se-ss+1);
	pushDown(index , ss , se);
	reset(index);

	if(ss > se || ss > qe || se < qs) return 0; //Valid?
	if(ss >= qs && se <= qe) //In range?
	{
		#ifdef intenseDebugQ
			printf("RETURN VAL = %i\n" , st[index].sum);
		#endif
		return st[index].sum;
	}

	if(ss != se)
		return ((queryUtil(lchild , ss , mid , qs , qe) + queryUtil(rchild , mid+1 , se , qs , qe)) %P);
}

void SegmentTree::update(int i , int j , int v , int typ)
{
	#ifdef debugU
		printf("---------------------------------------\n");
	#endif
	updateUtil(1 , 1 , n , i , j , v , typ);
	#ifdef debugU
		printSTArray();
	#endif
}

void SegmentTree::updateUtil(int index , int ss , int se  , int us , int ue , int v , int typ)
{
	#ifdef intenseDebugU
		printf("Update @ node %i S.R: [%i,%i] U.R: [%i,%i]\n", index , ss , se , us , ue);
	#endif

	int lchild = (index<<1), rchild = lchild+1, mid = ((ss+se)>>1);

	if(ss >= us && se <= ue) //In range?
	{
		switch(typ)
		{
			case 1:
				st[index].add = (st[index].add + v) %P;
				break;
			case 2:
				st[index].mul = (v * 1LL * st[index].mul) %P;
				st[index].add = (v * 1LL * st[index].add) %P;
				break;
			case 3:
				st[index].mul = 1;
				st[index].add = v;
				st[index].sum = 0;
				st[index].flg = true;
				break;
		}

		applyUpdates(index, se-ss+1);
		pushDown(index , ss , se);
		reset(index);

		#ifdef intenseDebugU
			printf("UPDATED\n");
		#endif

		return;	//No need to go further
	}

	applyUpdates(index, se-ss+1);
	pushDown(index , ss , se);
	reset(index);
	
	if(ss > se || ss > ue || se < us) return; //Valid?

	updateUtil(lchild , ss , mid , us , ue , v , typ);
	updateUtil(rchild , mid+1 , se , us , ue , v , typ);
	st[index].sum = (st[lchild].sum + st[rchild].sum) %P;
}

//Fast I/O
#define gc getchar_unlocked
template < class T >
inline void read(T &x) {
	register T c = gc();
	x = 0;
	bool neg = false;
	for(;(c<48 || c>57 );c = gc()) 
	  if ( c == '-') {
	      neg = true;
	      c = gc();
	      break;
	  }
	for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
	if ( neg ) x = -x;
}

#define pc(x) putchar_unlocked(x);
template <class T>
inline void write(T n) {
	bool neg = false ;
	if ( n < 0 ) neg = true, n = -n;
	T N = n, rev, count = 0;
	rev = N;
	if (N == 0) { pc('0'); pc('\n'); return ;}
	while ((rev % 10) == 0) { count++; rev /= 10;} 
	rev = 0;
	while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;} 
	if ( neg ) pc ('-');
	while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
	while (count--) pc('0');
	pc ('\n');
}

int main()
{
	int N, Q, typ, x, y, v;
	int A[100001];

	read(N); read(Q);
	for (int i = 1; i <= N; i++)
		read(A[i]);

	SegmentTree ST(N,A);

	while(Q--)
	{
		read(typ);read(x);read(y);
		if(typ != 4) {
			read(v);
			ST.update(x , y , v , typ);
		}
		else
			write(ST.query(x , y));
	}
}