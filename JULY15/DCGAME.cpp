#include <iostream>

using namespace std;

template <class T>
void print(char name[], T *A , int beg , int end) {
	cout << name << ": ";
	for (int i = beg; i <= end; i++)
		cout << A[i] << ",";
	cout << endl;
}

int main() {

	ios::sync_with_stdio(false);
	int N, M, A[1000001], K, imax;
	int n[1000001];
	char C, X;
	cin >> N >> M;
	memset(n , 0 sizeof(n));

	for(int i = 1; i<=N ; i++)
		cin >> A[i];

	for(int i = 1 ; i<=N ; i++) {
		imax = i; n[imax]++;
		for(int j = i+1 ; j<=N ; j++) {
			if(A[j] > A[imax]) imax = j;
			n[imax]++;
		}
	}

	print(A); print(n);
	
	return 0;
}