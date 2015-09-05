#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct question
{
	question(int _points , int _time):points(_points),time(_time){}

	int points;
	int time;
};

inline void clear(int *A , int siz) {
	memset(A , 0 , siz*sizeof(int));
}

inline int max(int a , int b) {
	return (a>b)?a:b;
}

int main() {
	
	ios::sync_with_stdio(false);

	int N , W , T , Ci , Pi , Ti;
	int dp[101][101];
	vector<question*> Q;
	clear(dp[0] , 101);

	cin >> T;

	while(T--) {

		cin >> N >> W;
		Q.resize(N+1);

		for (int i = 1; i <= N; i++) {
			cin >> Ci >> Pi >> Ti;
			Q[i] = new question(Ci*Pi , Ti);
		}

		for(int i = 1 ; i<=N ; i++) {
			dp[i][0] = 0;
			for(int j = 0 ; j<Q[i]->time ; j++)
				dp[i][j] = dp[i-1][j];
			for(int j = Q[i]->time ; j<=W ; j++)
				dp[i][j] = max(dp[i-1][j] , dp[i-1][j-Q[i]->time] + Q[i]->points);
		}

		cout << dp[N][W] << endl;
	}

	return 0;
}