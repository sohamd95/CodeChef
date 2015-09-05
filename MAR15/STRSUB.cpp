#include <cstdio>
#include <cstring>
 
#define ulli unsigned long long int
#define SIZ 101001
 
using namespace std;
 
inline int min(int a , int b)
{
	return (a<b)?a:b;
}

int main()
{
	int T , N , K , K2 , Q , L , R , d , cnt[2] , len , pref[101001] , calc[101001] , window , hi , lo;
	ulli ans  , t;
	char s[101001];
 
	scanf("%i" , &T);
 
	while(T--)
	{
		scanf("%i%i%i%s" , &N , &K , &Q , s);
 
		len = strlen(s);
		memset(pref , 0 , sizeof(int)*len);
		lo = calc[0] = cnt[0] = cnt[1] = 0;
		hi = pref[0] = d = 1;
		cnt[s[lo] - '0']++;

		while(hi != len)
		{
			cnt[s[hi] - '0']++;
			d++;
			if(cnt[0] > K || cnt[1] > K)
			{
				while(s[lo] != s[hi])
					{cnt[s[lo++] - '0']--; d--;}
				cnt[s[lo++] - '0']--;
				d--;
			}
			pref[hi] = pref[hi-1] + d;
			calc[hi] = calc[hi-1] + pref[hi] - pref[hi-1];
			hi++;
		}

		for(int i = 0 ; i <len ; i++)
		{
			printf("%i,", pref[i]);
		}
		printf("\n");
		for(int i = 0 ; i <len ; i++)
		{
			printf("%i,", calc[i]);
		}
		printf("\n");
 
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

			ans = calc[R-1] - calc[L-1];
			printf("%llu\n" , ans);
		}
	}
	
	return 0;
}