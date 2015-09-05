#include <cstdio>
#include <cstring>
using namespace std;

class LCG
{
private:
	unsigned int X;
	static const int a = 1103515245;
	static const int c = 12345;
	static const int m = 32768;

public:
	LCG(unsigned int S):X(S){}
	void srand(unsigned int S){X = S;}
	int nextInteger1()	{X = (a*X + c); return (X >> 16)%m;}
};

int main() 
{
	LCG r(0);
	int T , len;
	bool flg;
	char s[200001];

	scanf("%i" , &T);

	while(T--) {

		scanf("%s" , s);
		len = strlen(s);
		flg = false;

		for(int i = 0 ; i <= (1ul << 17) ; i++) {
			r.srand(i);
			if(!flg) {
				flg = true;
				for(int j = 0 ; j < len ; j++) {
					if(r.nextInteger1()%2 != s[j] - '0')
						{flg = false; break;}
				}
			} else {printf("LCG\n"); break;}
		}

		if(!flg) printf("Xorshift\n");

	}

	return 0;
}