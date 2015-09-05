#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
//Debugging
void print(string name, int *A , int beg , int end) {
	cout << name << ": ";
	for (int i = beg; i <= end; i++)
		cout << A[i] << ",";
	cout << endl;
}

struct p {
	p(int _n , int _times = 0):n(_n),times(_times) {}
	int n; 
	int times;
};

struct comp {
	bool operator () (const p *a , const p *b) {
		return (a->times > b->times);
	}
} c;

typedef std::vector<p*>::iterator it1;

int main() {

	ios::sync_with_stdio(false);
	int N, M, K, imax, tmp;
	char C, X;
	cin >> N >> M;
	vector<p*> A(N+1);

	for(int i = 1; i<=N ; i++) {
		cin >> tmp;
		A[i] = new p(tmp);
	}

	for(int i = 1 ; i<=N ; i++) {
		imax = i; A[i]->times++;
		for(int j = i+1 ; j<=N ; j++) {
			if(A[j]->n > A[imax]->n) imax = j;
			A[imax]->times++;
		}
	}

	it1 it = A.begin();
	std::sort(++it, A.end() , c);

	for(int i = 1 ; i<=N ; i++) {
		cout << A[i]->n;
	}

	return 0;
}