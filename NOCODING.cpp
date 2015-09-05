#include <cstdio>
#include <cstring>
using namespace std;

int main()

{
	char buffer , str[1001];
	short int T , s1 , sum;

	scanf("%hi",&T);

	while(T--)
	{
		sum = 0 , s1 = 0;
		scanf("%s" , str);
		buffer = str[0];
		short int len = strlen(str);

		for(short int i = 1 ; i<len; i++)
		{
			s1 = (str[i] - buffer);
			if(s1 < 0) s1 += 26;
			sum += s1;
			sum++;
			buffer = str[i];
		}
		sum += 2;
		if(sum <= (len*11)) printf("YES\n");
		else printf("NO\n");
	}	

	return 0;
}