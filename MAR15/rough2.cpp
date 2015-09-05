#include <cstdio>
#include <cstring>
 
#define ulli unsigned long long int
 
using namespace std;
 
inline int min(int a , int b)
{
	return (a<b)?a:b;
}

int main()
{
	int T , N , K , K2 , Q , L , R , d , cnt[2] , len , pref[101001] , window , hi , lo;
	ulli ans  , t;
	char s[101001];
 
	scanf("%i" , &T);
 
	while(T--)
	{
		scanf("%i%i%i%s" , &N , &K , &Q , s);
 
		len = strlen(s);
		memset(pref , 0 , sizeof(int)*len);
		cnt[0] = cnt[1] = 0;
		hi = lo = 0;

		while(hi != len)
		{
			cnt[s[hi] - '0']++;
			if(cnt[0] > K || cnt[1] > K)
			{
				while(s[lo] != s[hi])
					cnt[s[lo++] - '0']--;
				cnt[s[lo++] - '0']--;
			}
			for(int i = lo ; i<=hi ; i++)
				pref[i]++;
			hi++;
		}
 
		while(Q--)
		{
			scanf("%i%i" , &L , &R);
			if(L == R)
			{
				printf("1\n");
				continue;
			}
 
			window = R-L+1;
			t = (ulli) min(window , K);
			ans = t*window + t - ((t*(t+1)) >> 1);
 
			if(window <= K)
			{
				printf("%llu\n", ans);
				continue;
			}

			d = R-L+1;
			ans = 0;
			for(int i = L-1 ; i<R ; i++)
				ans += min(d-- , pref[i]);
			printf("%llu\n", ans);
		}
	}
	
	return 0;
}