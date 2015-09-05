#include <cstdio>

using namespace std;

int process(char *str , int i , int j , int K) {
	if(j-i+1 <= K)
		return 0;
	int cnt = 0;

	for(int k = i+K ; k<=j ; k += (K+1)) {
		if(k == j)
			str[k-1] = (str[k-1] == '0')?'1':'0';
		else
			str[k] = (str[k] == '0')?'1':'0';
		cnt++;
	}
	return cnt;
}

int main() {

	int T , N , K , prev , ans;
	bool flg;
	char str[100000];

	scanf("%i" , &T);

	while(T--) {

		ans = 0;
		prev = 0;
		flg = false;
		scanf("%i%i" , &N , &K);
		scanf("%s" , str);

		if(K == 1) {
			for(int i = 0 ; i<N ; i++) {
				if((i%2) && str[i] != '0')
					ans++;
				else if(!(i%2) && str[i] != '1')
					ans++;
			}
			if(N - ans < ans) {
				for(int i = 0 ; i<N ; i++) {
					if(i%2)
						str[i] = '1';
					else str[i] = '0';
				}
				ans = N - ans;
			} else {
				for(int i = 0 ; i<N ; i++) {
					if(i%2)
						str[i] = '0';
					else str[i] = '1';
				}
			}
		}
		else {
			for(int i = 0 ; i<N-1 ; i++) {
				if(str[i] != str[i+1]) {
					flg = true;
					ans += process(str , prev , i , K);
					prev = i+1;
				}
			}
			ans += process(str , prev , N-1 , K);
		}

		printf("%i\n%s\n", ans , str);
	}

	return 0;
}