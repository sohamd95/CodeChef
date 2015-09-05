#include <iostream>
#include <cmath>
#include <cstring>

#define INT_MAX 999

const int MAXARR = 262144;

using namespace std;

//For debugging
template <class T>
void print(char name[], T *A , int beg , int end) {
	cout << name << ": ";
	for (int i = beg; i <= end; i++)
		cout << A[i] << ",";
	cout << endl;
}

//Fast I/O
#define gc getchar_unlocked
template < class T >
inline void scan(T &x) {
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

class SegmentTree
{
public:
	SegmentTree(int);				//Constructor
	void update(int , int , int);	//User-end update function
	int query(int);					//User-end query function
	void reset(int);				//Clear
 
private:
 
	void updateUtil(int , int , int , int , int , int);	//Update with lazy propogation
	int queryUtil(int , int , int , int);				//Query
 
	int n;
	int *st;
	int *lazy;
};
 
SegmentTree::SegmentTree(int _n = 0):n(_n)
{
	st = new int [MAXARR];
	lazy = new int [MAXARR];
	for(int i = 0 ; i<MAXARR ; i++)
		st[i] = lazy[i] = INT_MAX;
}
 
void SegmentTree::reset(int n) {
	this->n = n;
	for(int i = 0 ; i<MAXARR ; i++)
		st[i] = lazy[i] = INT_MAX;
}
 
int SegmentTree::query(int i)
{
	return queryUtil(1 , 1 , n , i);
}
 
int SegmentTree::queryUtil(int node , int a , int b , int i)
{
	int lchild = (node<<1), rchild = (node<<1)+1, mid = ((a+b)>>1);

	if ( lazy[node] != INT_MAX ) {
		st[node] = min (st[node], lazy[node]);
		if ( a != b ) {
			lazy[lchild] = min (lazy[lchild], lazy[node]);
			lazy[rchild] = min (lazy[rchild], lazy[node]);
		}
		lazy[node] = INT_MAX;
	}
 
	if ( a > i || b < i ) return INT_MAX;
	if ( a >= i && b <= i ) return st[node];

	return (i<=mid)?queryUtil(lchild, a, mid, i):queryUtil(rchild, mid + 1, b, i);
}
 
void SegmentTree::update(int i , int j , int v)
{
	updateUtil(1 , 1 , n , i , j , v);
}
 
void SegmentTree::updateUtil(int i , int a , int b  , int l , int r , int cost)
{
	int lchild = (i<<1), rchild = (i<<1)+1, mid = ((a+b)>>1);

	if ( lazy[i] != INT_MAX ) {
		st[i] = min (st[i], lazy[i]);
		if ( a != b ) {
			lazy[lchild] = min (lazy[lchild], lazy[i]);
			lazy[rchild] = min (lazy[rchild], lazy[i]);
		}
		lazy[i] = INT_MAX;
	}
 
	if ( a > r || b < l ) return ;

	if ( a >= l && b <= r ) {
		st[i] = min (st[i], cost );
		if ( a != b ) {
			lazy[lchild] = min (lazy[lchild], cost);
			lazy[rchild] = min (lazy[rchild], cost);
		}
		return ;
	}
 
	updateUtil ( lchild, a, mid, l, r, cost );
	updateUtil ( rchild, mid + 1, b, l, r, cost );
	st[i] = min (st[lchild], st[rchild]);
}

int main() {

	int T , N , K , M , L , R , C;
	long long int dp[501];
	int rating[100001], cost[100001];
	SegmentTree tree;
 
	scan(T);
 
	while(T--) {
 
		scan(N);scan(K);scan(M);
		tree.reset(N);
 
		for (int i = 0; i < 501; i++)
			dp[i] = 0;	
		
		for(int i = 1 ; i<=N ; i++)
			scan(rating[i]);
 
		for(int i = 1 ; i<=M ; i++) {
			scan(L);scan(R);scan(C);
			tree.update(L,R,C);
		}
		for (int i = 1; i<=N ; i++)
			cost[i] = tree.query(i);
		
		for (int i = 1; i<=N; i++) {
			for (int j = K ; j>0 ; j--)
				dp[j] = (j<cost[i])?(dp[j] + rating[i]):max(dp[j-cost[i]] , dp[j]+rating[i]);
			dp[0] += rating[i];
		}
		
		write(dp[K]);
	}
 
	return 0;
}  