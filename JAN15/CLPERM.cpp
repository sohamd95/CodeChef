#include <cstdio>
#include <algorithm>
#define lli long long int
 
using namespace std;
 
lli A[100000];
 
inline lli sumTill(lli n)
{
    return ((n*(n+1))/2);
}
 
int main()
{
	lli T ,N,K,t,tot,i;
	bool flg;
 
	scanf("%lli" , &T);

	while(T--)
	{
        tot = 0;
        flg = false;

        scanf("%lli%lli", &N , &K);

        for(int j = 0 ; i<K ;j++)
        {
           scanf("%lli" , &t);
        	A[j] = t;
        }

        std::sort(A , A+K);

        for(int j = 0 ; j<K ; j++)
        {
       		if(sumTill(A[j]-1)-tot <A[j])
        			{flg = true;break;}
       		tot += A[j];
        }

        if(flg)
        {
        	if(A[i] % 2) printf("Chef\n");
       		else printf("Mom\n");
        }
        else
        {
         	lli test = sumTill(N);
         	if((test-tot+1) % 2) printf("Chef\n");
         	else printf("Mom\n");
        }
	}
 
	return 0;
} 