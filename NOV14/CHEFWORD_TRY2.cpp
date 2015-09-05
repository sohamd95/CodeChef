#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int T , N , K , len;
    double pi = 0 , prob[26][26];
    char str[100] , word[100];

    scanf("%i" , &T);
     
    while(T--)
    {
    scanf("%i%i", &N, &K);
    scanf("%s" , str);
    len = strlen(str);
    //probs = new double [N];
     
    //for(int i = 0 ; i<K ; i++)
    // probs[i] = 0;
     
    for(int i = 0 ; i<26 ; i++)
    for(int j = 0 ; j<26 ; j++)
    {
    scanf("%lf" , prob[i][j]);
    }
    //G.showAdjList();
    //G.showWeightMatrix();
     
    while(N--)
    {
    double p3 = 1;
    scanf("%s" , word);
    if(strlen(word) != len)
    continue;
    else
    {
    double p4 = 0;
     
    for(int i = 0 ; i<len ; i++)
    {
    p4 = 0;
	p3 *= p4;
    if(!p3) break;
     
    //printf("itm: %lf,%i\n\n", p3,i);
    }
    pi += p3;
    //printf("%lf\n", p3);
    }
    }
    printf("%lf\n", prob);
    }
    return 0;
}