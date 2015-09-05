#include <iostream>
#include <cmath>
#include <cstring>

#define why_Wont_This_Shit_Work
using namespace std;
typedef unsigned long long int llu;
typedef long long int lli;
int count[320][100001] = {0};

template <class T>
void print(T *A , int beg , int end, char name[] = NULL) {
	if(name) cout << name << ": ";
	for (int i = beg; i <= end; i++)
		cout << A[i] << ",";
	cout << endl;
}

class SegmentTree
{
public:
	SegmentTree(int n , int *A):N(n){constructUtil(A,1,1,N);}
	lli query(int , int);
	void update(int , int);

private:

	void constructUtil(int* , int , int , int);
	lli queryUtil(int , int , int , int, int);
	void updateUtil(int , int , int , int , int);

	int N;
	lli st[262144];
};

void SegmentTree::constructUtil(int *A , int node , int ss , int se)
{
	if(ss == se)
	{
		st[node] = A[ss];
		return;
	}
	int mid = ((ss+se)>>1), lchild = (node<<1), rchild = lchild+1;
	constructUtil(A , lchild , ss , mid);
	constructUtil(A , rchild , mid+1 , se);
	st[node] = st[lchild] + st[rchild];
}

lli SegmentTree::queryUtil(int node , int ss , int se , int qs , int qe)
{
	if(ss > se || ss > qe || se < qs) return 0;
	if(ss >= qs && se <= qe) return st[node];
	int mid = ((ss+se)>>1), lchild = (node<<1), rchild = lchild+1;
	return (queryUtil(lchild , ss , mid , qs , qe) + queryUtil(rchild , mid+1 , se , qs , qe));
}

lli SegmentTree::query(int L , int R)
{
	return queryUtil(1 , 1 , N , L , R);
}

void SegmentTree::updateUtil(int node , int ss , int se , int i , int val)
{
	#ifdef why_Wont_This_Shit_Work
		printf("Update @ node %i S.R: [%i,%i] U.P: [%i] U.V: [%i]\n", node , ss , se , i , val);
	#endif
	if(ss > se || ss>i || se<i) return;
	if(ss == i) {st[node] = val; return;}
	int mid = ((ss+se)>>1), lchild = (node<<1), rchild = lchild+1;
	if(i <= mid) updateUtil(lchild , ss , mid , i , val);
	else updateUtil(rchild , mid+1 , se , i , val);
	st[node] = st[lchild] + st[rchild];
}

void SegmentTree::update(int i , int val)
{
	updateUtil(1 , 1 , N , i , val);
}

struct Function
{
	Function(int _L , int _R , int _b):L(_L),R(_R),b(_b){}
	int L, R, b;
};

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

int main() {

	int N , A[100001], Li, Ri, Q, typ, x, y;
	int bucket_siz, total_buckets;
	llu bucket[320] = {0};
	Function *F[100001];
	
	read(N);
	bucket_siz = floor(sqrt(N));
	total_buckets = (N/bucket_siz)+1;
	//cout<<"sqrt: "<<bucket_siz<<endl;
	
	for (int i = 1; i <= N; i++)
		read(A[i]);
	SegmentTree tree(N,A);
	for(int i = 0, bucket_num ; i<N ; i++)
	{
		read(Li); read(Ri);
		bucket_num = (i/bucket_siz);
		F[i] = new Function(Li , Ri , bucket_num);
		count[bucket_num][Li]++, count[bucket_num][Ri+1]--;
	}
	for (int i = 0; i < total_buckets ; i++)
		for (int j = 1; j <= N; j++)
			count[i][j] += count[i][j-1];
			
	for(int i = 0 ; i<N ; i++)
		bucket[F[i]->b] += tree.query(F[i]->L , F[i]->R);
		
	//print(bucket , 0 , total_buckets-1 , "Buckets");

	read(Q);
	for(int i = 1 ; i<=Q ; i++)
	{
	 	read(typ); read(x); read(y);
	 	if(typ == 1) //Update
	 	{
	 		tree.update(x , y);
	 		for (int j = 0; j < total_buckets; ++j)
	 			bucket[j] += count[j][x] * (y - A[x]);
	 		A[x] = y;
	 		//print(bucket , 0 , total_buckets-1 , "Buckets");
	 	}
	 	else //Query
	 	{
	 		x--; y--;
	 		llu sum = 0;
	 		while(x %bucket_siz && x<=y) {sum += tree.query(F[x]->L , F[x]->R), x++;}
	 		while(x + bucket_siz-1 <= y) {sum += bucket[F[x]->b], x += bucket_siz;}
	 		while(x <= y) {sum += tree.query(F[x]->L , F[x]->R); x++;}
	 		write(sum);
	 	}
	}
	
	return 0;
}