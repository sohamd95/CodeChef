#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	short int T , N , N2 , N3 , i=0;
	int c = 0;
	char **ch;
	bool flg = false;

	scanf("%hi",&T);

	while(T--)
	{
		scanf("%hi", &N);
		N3 = N2 = N;
		i = 0;
		flg = false;

		ch = new char*[N];
		bool flg2 = true;

		while(N3--)
		{
			N2 = N;
			ch[i] = new char[N];
			scanf("%s", ch[i]);
			if(i == N-1)
			{
				for(int j = 0 ;j<N ; j++)
					if(ch[i][j] == '.') {flg2 = false; break;}
				if(flg2)
					{printf("0\n"); break;}
			}
			while(--N2)
			{
				if(ch[i][N2] == '#')
					{flg = true; break;}
			}
			//N2--;
			if(flg)
				while(N2--)
					if(ch[i][N2]!='#')ch[i][N2]='N';
			i++;
		}
		if(flg2) continue;
		
		for(int i = N-1 ; i>=0 ; i--)
		{
			flg = false;
			for(int j = N-1 ; j>=0 ; j--)
				if(flg) ch[j][i] = 'N';
				else if(ch[j][i] == '#') flg = true;
		}

		//for(int i = 0 ; i<N ; i++)
		//	{for(int j = 0; j<N ; j++)
		//					{char b= ch[i][j]; printf("%c ", b);}printf("\n");}

		c = 0;
		for(int i = 0 ; i<N ; i++)
			for(int j = 0 ; j<N ; j++)
				if(ch[i][j] == '.') c++;
		
		printf("%i\n", c);	
	}
	return 0;
}