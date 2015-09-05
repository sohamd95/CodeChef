#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	int T, len, switches, pos, lenA, lenB;
	bool flg, flg1;
	string A , B;
	cin >> T;

	while(T--) {
		cin >> A >> B;
		len = A.length();
		flg1 = false;
		lenA = lenB = pos = switches = 0;
		while(lenA < len) {
			if(A[lenA] == '#') {flg1 = true; break;}
			lenA++;
		}
		while(lenB < len && B[lenB] != '#') lenB++;
		if(flg1 && (lenA == lenB)){cout << "No\n"; continue;}
		if(lenA > lenB) flg = true;
		else flg = false;

		while(pos+1 != len) {
			if(A[pos] == '#' && B[pos] == A[pos]) {switches = -1; break;}
			if((flg && A[pos+1] == '.') || (!flg && B[pos+1] == '.')) pos++;
			else if(flg) {
				if(B[pos+1] == '.') {switches++; flg = !flg; pos++;}
				else {switches = -1; break;}
			} else {
				if(A[pos+1] == '.') {switches++; flg = !flg; pos++;}
				else {switches = -1; break;}
			}
		}

		if(switches == -1) cout << "No\n";
		else cout << "Yes\n" << switches << "\n";
	}
	return 0;
}