#include <cstdio>
#include <cstring>

using namespace std;

int min(int x , int y) {
	return ((x < y)? x : y);
}

void check(char str[] , int cur , int &cnt , char prev , int &len) {

	if(cur == len) return;

	if(str[cur] == '+') {
		if(prev == '-') {
			prev = '+';
			check(str , cur+1 , cnt , prev , len);
		}
		else {
			prev = '-';
			cnt++;
			check(str , cur+1 , cnt , prev , len);
		}
	}
	else {
		if(prev == '+') {
			prev = '-';
			check(str , cur+1 , cnt , prev , len);
		}
		else {
			prev = '+';
			cnt++;
			check(str , cur+1 , cnt , prev , len);
		}
	}
}

int main() {

	int T , cnt1 = 0 , cnt2 = 1 , len;
	char str[100000], ch , ch2;

	scanf("%i" , &T);

	while(T--) {

		scanf("%s" , str);

		cnt1 = 0 ;
		cnt2 = 1;
		len = strlen(str);
		ch = (str[0] == '+')? '+' : '-';
		ch2 = (str[0] == '+')? '-' : '+';
		check(str , 1 , cnt1 , ch , len);
		check(str , 1 , cnt2 , ch2 , len);

		printf("%i\n", min(cnt1 , cnt2));
	}

	return 0;
}