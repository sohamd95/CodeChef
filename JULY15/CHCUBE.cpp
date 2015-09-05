#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int T;
	string col[6];

	cin >> T;

	while(T--) {

		// front, back, left, right, top and bottom
		for(int i = 0 ; i<6 ; i++)
			cin >> col[i];
		if(col[0] == col[2] && col[2] == col[5]) cout << "YES\n";
		else if(col[0] == col[3] && col[3] == col[5]) cout << "YES\n";
		else if(col[0] == col[3] && col[3] == col[4]) cout << "YES\n";
		else if(col[0] == col[2] && col[2] == col[4]) cout << "YES\n";
		else if(col[1] == col[3] && col[3] == col[4]) cout << "YES\n";
		else if(col[1] == col[2] && col[2] == col[4]) cout << "YES\n";
		else if(col[1] == col[2] && col[2] == col[5]) cout << "YES\n";
		else if(col[1] == col[3] && col[3] == col[5]) cout << "YES\n";
		else cout << "NO\n";

	}

	return 0;
}