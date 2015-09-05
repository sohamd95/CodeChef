#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
	int T, N, a[101], F;
	double dp[10001], p[101], ans;
	cout << std::fixed << std::setprecision(6);
	cin >> T;

	while(T--)
	{
		F = 0; ans = 0;
		cin >> N;
		for(int i = 1 ; i<=N ; i++)
			cin >> a[i], F += a[i];
		for(int i = 1 ; i<=N ; i++)
			cin >> p[i], p[i] /= 100.0;
		memset(dp , 0 , sizeof dp);
		dp[0] = 1.0;

		for (int i = 1; i<=N; i++) {
			for(int j = F ; j>0 ; j--)
				dp[j] = (a[i]<=j)?((dp[j-a[i]] * p[i]) + (dp[j] * (1.0-p[i]))) : (dp[j] * (1.0-p[i]));
			dp[0] *= (1.0-p[i]);
		}
		for(int i = ((F+1)>>1) ; i<=F ; i++)
			ans += dp[i];

		cout << ans << endl;
	}

	return 0;
}