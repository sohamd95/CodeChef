#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>

#define TIMES(i) A[i].second
#define EL(i) A[i].first
//#define debug

using namespace std;

typedef long long int lli;
typedef deque<pair <int,lli> >::iterator it1;

deque<pair <int,lli> > A;
int N;

struct sort_by_first {
    bool operator()(const std::pair<int,lli> &left, const std::pair<int,lli> &right) {
        return (left.first > right.first);
    }
} comp;

lli query(int qs , int qe , char C , int K) {
	int mid = (qs+qe+1)>>1;
	#ifdef debug
		cout << "Query called on [" << qs << "," << qe << "] mid = " << mid << ", EL(" << mid << ") = " << EL(mid) << ", K = " << K << "\n";
	#endif
	if(qs > qe) return 0;
	if(qs == qe) {
		switch(C) {
			case '<':
				return TIMES(qs + ((EL(qs) < K)?0:1));
			case '>':
				return TIMES(1) - TIMES(qs+((EL(qs) > K)?1:0));
			case '=':
				if(K == EL(qs))
					return TIMES(qs) - ((qs != N)?TIMES(qs+1):0);
				else return 0;
		}
	}
	if(EL(mid) == K) {return query(mid , mid , C , K);}
	else if(K <= EL(mid)) {return query(((mid != qe)?mid+1:qe) , qe , C , K);}
	else {return query(qs , ((mid != qs)?mid-1:qs) , C , K);}
}

void print() {
	for(int i = 1 ; i <= N ; i++) {
		cout << "{" << EL(i) << "," << TIMES(i) << "} ";
	} cout << endl;
}

int main() {

	ios::sync_with_stdio(false);

	int M, K, imax, tmp;
	char C, X;
	stack <int> S;

	cin >> N >> M;
	A.resize(N+1);
	
	for(int i = 1; i<=N ; i++)
		cin >> EL(i);

	for(int i = N ; i >= 1 ; i--) {
		while(!S.empty() && (EL(S.top()) <= EL(i))) S.pop();
		if(S.empty()) {TIMES(i) = N-i; S.push(i);}
		else {TIMES(i) = S.top()-i-1; S.push(i);}
	}
	while(!S.empty()) S.pop();
	for(int i = 1 ; i <= N ; i++) {
		while(!S.empty() && (EL(S.top()) < EL(i))) S.pop();
		if(S.empty()) {tmp = TIMES(i)*(i-1); TIMES(i) += (i+tmp); S.push(i);}
		else {tmp = TIMES(i)*(i-S.top()-1); TIMES(i) += (i-S.top()+tmp); S.push(i);}
	}
	
	sort(++A.begin() , A.end() , comp);
	
	print();
	
	int count = TIMES(1), dup = 0;

	for (it1 i = A.begin(); i != --A.end() ; ) {
	  if ((i+1)->first == i->first) {
	  	i = A.erase(i);
	  	count += i->second;
	  	dup++;
	  } else {
	  	i->second = count;
	  	count = (i+1)->second;
	  	++i;
	  }
	}  (*(--A.end())).second = count; N -= dup;
	
	print();

	for(int i = N-1 ; i>=1 ; i--)
		TIMES(i) += TIMES(i+1);
	
	//print();
	
	lli freq;
	for(int i = 1 ; i<=M ; i++) {
		cin >> C >> K >> X;
		switch(C) {
			case '<':
				if(K > EL(1)) freq = TIMES(1);
				else if(K <= EL(N)) freq = 0;
				else freq = query(1 , N , C , K);
				break;
			case '>':
				if(K < EL(N)) freq = TIMES(1);
				else if(K >= EL(1)) freq = 0;
				else freq = query(1 , N , C , K);
				break;
			case '=':
				if(K > EL(1) || K < EL(N)) freq = 0;
				else freq = query(1 , N , C , K);
				break;
		}
		cout << C << " " << K << " :\t" << freq;
		// if(freq %2) cout << ((X == 'D')?"D":"C");
		// else cout << ((X == 'D')?"C":"D");
		cout << endl;
	}

	return 0;
}