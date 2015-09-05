#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

inline int min(int a , int b) {
	return (a < b)?a:b;
}

void calc(char s[] , int cur , queue<int> &LIB , queue<int> &LIG , char prev , int len , int &cost) {
	if(cur == len) {
		if(!LIB.empty() || !LIG.empty())
			cost = -1;
		return;
	}
	
	switch(s[cur]) {
		case 'B':
		{
			switch(prev)
			{
				case 'B':
				{
					LIB.push(cur);
					if(!LIG.empty()) {
						cost += (int) abs((double)(LIB.front() - LIG.front()));
						LIG.pop();
						LIB.pop();
					}

					calc(s , cur+1 , LIB , LIG , 'G' , len , cost);
					break;
				}

				case 'G':
				{
					calc(s , cur+1 , LIB , LIG , 'B' , len , cost);
					break;
				}
			}
			break;
		}
		case 'G':
		{
			switch(prev)
			{
				case 'B':
				{
					calc(s , cur+1 , LIB , LIG , 'G' , len , cost);
					break;
				}

				case 'G':
				{
					LIG.push(cur);
					if(!LIB.empty()) {
						cost += (int) abs((double)(LIB.front() - LIG.front()));
						LIG.pop();
						LIB.pop();
					}

					calc(s , cur+1 , LIB , LIG , 'B' , len , cost);
					break;
				}
			}
			break;
		}
	}
}

int main()
{
	int T , type , len;
	char s[100001];
	queue <int> LIB , LIG;

	scanf("%i" , &T);

	while(T--)
	{
		scanf("%i%s" , &type , s);
		len = strlen(s);

		switch(type)
		{
			case 0:
			{
				int cnt = 0 , Gcnt = 0;
				char ch = 'G';
				for(int i = 0 ; i<len ; i++)
				{
					if(s[i] != ch)
						cnt++;
					if(s[i] == 'G')
						Gcnt++;
					ch = (ch == 'G')? 'B' : 'G';
				}
				if(abs((double)(len - (Gcnt<<1))) > 1)
				{
					printf("-1\n");
					continue;
				}
				if(len % 2)
				{
					if(Gcnt > (len>>1))
						printf("%i\n", (cnt>>1));
					else printf("%i\n", ((len-cnt)>>1));
				}
				else printf("%i\n", (cnt < len-cnt)?(cnt>>1):((len-cnt)>>1));
				break;
			}

			default:
			{
				while(!LIB.empty()) {
					LIB.pop();
				}
				while(!LIG.empty()) {
					LIG.pop();
				}

				if(len % 2) {
					int Gcnt = 0;
					for(int i = 0 ; i<len ; i++)
						if(s[i] == 'G')
							Gcnt++;

					if(abs((double)(len - (Gcnt<<1))) > 1)
					{
						printf("-1\n");
						continue;
					}
					if((len>>1) < Gcnt) {
						int cost1 = 0;
						calc(s , 0 , LIB , LIG , 'B' , len , cost1);
						printf("%i\n", cost1);
					} else {
						int cost1 = 0;
						calc(s , 0 , LIB , LIG , 'G' , len , cost1);
						printf("%i\n", cost1);
					}

				} else {
					int cost1 = 0, cost2 = 0;
					calc(s , 0 , LIB , LIG , 'B' , len , cost1);
					calc(s , 0 , LIB , LIG , 'G' , len , cost2);
					
					printf("%i\n", min(cost1 , cost2));
				}
				break;
			}
		}
	}
	return 0;
}