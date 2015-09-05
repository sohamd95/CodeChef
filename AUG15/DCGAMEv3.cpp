#include <vector>
#include <stack>
#include <cstdio>
#include <algorithm>
 
#define TIMES(i) A[i].second
#define EL(i) A[i].first
//#define debug
 
using namespace std;
 
typedef long long int lli;
typedef vector<pair <int,lli> >::iterator v_it;
 
vector<pair <int , lli> > A, B;
int N;
 
struct sort_by_first {
    bool operator()(std::pair<int,lli> &left , const std::pair<int,lli> &right) {
        return (left.first < right.first);
    }
    bool operator()(const int &val, const std::pair<int,lli> &right) {
        return (val < right.first);
    }
    bool operator()(const std::pair<int,lli> &right , const int &val) {
        return (val > right.first);
    }
} comp;
 
int main() {
 
	int M, K, imax, tmp;
	char C, X;
	stack <int> S;
 
	scanf("%i%i" , &N , &M);
	A.resize(N+1);
	B.resize(N+1);
	
	for(int i = 1; i<=N ; i++) scanf("%i", &EL(i));
 
	for(int i = N ; i >= 1 ; i--) {
		while(!S.empty() && (EL(S.top()) <= EL(i))) S.pop();
		if(S.empty()) {TIMES(i) = N-i; S.push(i);}
		else {TIMES(i) = S.top()-i-1; S.push(i);}
	}
	while(!S.empty()) S.pop();
	for(int i = 1 ; i <= N ; i++) {
		while(!S.empty() && (EL(S.top()) < EL(i))) S.pop();
		if(S.empty()) {TIMES(i) += (i+TIMES(i)*(i-1)); S.push(i);}
		else {TIMES(i) += ((i-S.top())+(TIMES(i)*(i-S.top()-1))); S.push(i);}
	}
 
	std::sort(++A.begin(), A.end(), comp);
	
	B[0] = A[1];
	int prev = A[1].first;
	int j = 0;
	for (int i = 2; i<=N; ++i)
	{
		if(A[i].first == prev) B[j].second += A[i].second;
		else {
			++j;
			B[j].first = A[i].first;
			B[j].second = B[j-1].second + A[i].second;
			prev = B[j].first;
		}
	} B.resize(j+1);
 
	lli freq;
	v_it begin = B.begin(), end = B.end(), last = --B.end(), cur, it;
	
	for(v_it i = B.begin() ; i != B.end() ; ++i) {
		printf("{%i,%lli} " , i->first , i->second);
	} printf("\n");
	
	for(int i = 1 ; i<=M ; i++) {
		scanf("\n%c %i %c" , &C , &K , &X);
		if(C == '>') it = std::upper_bound(begin, end, K, comp);
		else it = std::lower_bound(begin, end, K, comp);
 
		switch(C) {
			case '<':
				if(it == end)
					freq = last->second;
				else if(it == begin)
					freq = 0;
				else freq = ((it->first >= K)?(--it):(it))->second;
				break;
				
			case '>':
				if(it == end)
					freq = 0;
				else if(it != begin)
					freq = last->second - (--it)->second;
				else freq = last->second;
				break;
				
			case '=':
				if(it->first == K) {
					if(it != begin) {
						cur = it--;
						freq = cur->second - it->second;
					} else freq = it->second;
				} else freq = 0;
				break;
		}
		// printf("%c %i : %i\n" , C , K , freq);
		if(freq %2) printf("%c" , ((X == 'D')?'D':'C'));
		else printf("%c" , ((X == 'D')?'C':'D'));
	}
 
	return 0;
} 