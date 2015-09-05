#include <iostream>

using namespace std;

int main() {

	int K, maxAi;

	cin >> maxAi >> K;

	for(int Ai = 2*K+1 ; Ai<=maxAi ; Ai++) {
		for (int Aj = K+1; Aj < maxAi+1; ++Aj)
		{
			cout << Ai << " mod " << Aj << " = " << Ai % Aj << endl;
		}
	}

	return 0;
}