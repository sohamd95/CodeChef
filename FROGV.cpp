#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct frog {

	frog(int _id , int _x):id(_id),x(_x){}

	int id;
	int x;
};

struct compFuncObj {
	bool operator () (const frog *a , const frog *b) {
		return (a->x > b->x);
	}
} SortByX;

int main() {

	ios::sync_with_stdio(false);

	int N , K , P , x , A , B;
	int maxDist[100000];
	frog* Frog[100000];

	cin >> N >> K >> P;

	for(int i = 0 ; i<N ; i++) {
		cin >> x;
		Frog[i] = new frog(i , x);
	}

	std::sort(Frog , Frog+N , SortByX);
	maxDist[Frog[0]->id] = Frog[0]->x + K;

	for(int i = 1 ; i<N ; i++) {
		if(Frog[i-1]->x - Frog[i]->x <= K)
			maxDist[Frog[i]->id] = maxDist[Frog[i-1]->id];
		else maxDist[Frog[i]->id] = Frog[i]->x + K;
	}

	while(P--) {
		cin >> A >> B;
		if(maxDist[A-1] == maxDist[B-1])
			cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}