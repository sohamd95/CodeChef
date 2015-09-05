#include <iostream>
 
using namespace std;
 
inline void swap(int &a , int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
 
int main() {
 
	ios::sync_with_stdio(false);
	cout.precision(6);
 
	int T , T1 , T2 , t1 , t2 , tmp;
	double a , b , ans;
 
	cin >> T;
 
	while(T--) {
 
		cin >> T1 >> T2 >> t1 >> t2;
 
		if(T1 > T2) {
			swap(t1 , t2);
			swap(T1 , T2);
		}
		if(t1 > T2) t1 = T2;
		if(t2 > T1) t2 = T1;
 
		a = 0.5 * T1 * T1;
		if(t2 < T1)
			a -= 0.5 * (T1 - t2) * (T1 - t2);
 
		if(T1 + t1 <= T2)
			b = 1.0 * T1 * t1;
		else {
			b = 0.5 * T1 * T1;
			b += 1.0 * T1 * (T2 - T1);
			b -= 0.5 * (T2 - t1) * (T2 - t1);
		}
		ans = (a + b)/(1LL * T1 * T2);
		
		cout << fixed << ans << endl;
	}
 
	return 0;
} 