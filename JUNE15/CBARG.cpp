#include <cstdio>

using namespace std;

int main() {

	int T , N , Mi , prev;
	unsigned long long int Malloc;

	scanf("%i" , &T);

	while(T--) {
		scanf("%i" , &N);
		Malloc = 0;
		prev = 0;

		while(N--) {
			scanf("%i" , &Mi);

			if(prev < Mi)
				Malloc += (Mi-prev);
			prev = Mi;
		}
		printf("%llu\n", Malloc);
	}

	return 0;
}