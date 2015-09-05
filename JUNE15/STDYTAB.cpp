#include <cstdio>
#include <string>
#include <cstring>
#define P 1000000000L
typedef unsigned long long int ulli;
using namespace std;

int C[4001][2001];
int dp[2001][2001];

inline int f(int k ,int M) {
	return C[M-1+k][M-1];
}

void preproc() {
	for (int i=0; i<=4000; i++)
    {
        for (int k=0; k<=2000 && k<=i; k++)
            if (k==0 || k==i)
                C[i][k] = 1;
            else
                C[i][k] = (C[i-1][k-1] + C[i-1][k]) %P;
    }
}

void calc(int M) {

	int tmp[2001] , tmp2[2001];
	ulli g;
	
    tmp2[0] = tmp[0] = 1;
    
    for(int k=1 ; k<=M ; k++) {
    	tmp[k] = (tmp[k-1] + f(k,M)) %P;
    	tmp2[k] = f(k,M);
    }
    dp[1][M] = tmp[M];

    for(int j=2 ; j<=2000 ; j++) {
    	for(int l=1 ; l<=M ; l++) {
    		g = tmp[l];
    		g *= tmp2[l];
    		g = g%P;
    		tmp[l] = (tmp[l-1] + (int)g) %P;
    		dp[j][M] = tmp[M];
    	}
    }
}

int main() {
	
	preproc();
	
	int T , M , N;
	bool calculated[2001];
	scanf("%i" , &T);
	memset(calculated , false , 2001);

	while(T--) {
		scanf("%i%i" , &N , &M);
		if(calculated[M])
			printf("%i\n", dp[N][M]);
		else {
			calc(M);
			calculated[M] = true;
			printf("%i\n", dp[N][M]);
		}
	}

	return 0;
}