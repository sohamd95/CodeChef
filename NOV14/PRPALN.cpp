#include <cstdio>
#include <cstring>

using namespace std;

bool checkPaln(char *str , int lo , int hi , bool flg)
{
	if(lo >= hi) return true;
	else if(str[lo] == str[hi]) return checkPaln(str , lo+1 , hi-1 , flg);
	else if( (str[lo] == str[hi - 1]) && (str[lo + 1] == str[hi]) )
		return !flg && (checkPaln(str , lo , hi-1 , true) || checkPaln(str , lo+1 , hi , true));
	else if(str[hi - 1] == str[lo]) return !flg && checkPaln(str , lo , hi-1 , true);
	else if(str[lo + 1] == str[hi]) return !flg && checkPaln(str , lo+1 , hi , true);
	else return false;
}

int main()
{
	int T;
	char str[100010];
	int i;

	scanf("%i" , &T);

	while(T--)
	{
		scanf("%s" , str);
		if(checkPaln(str , 0 , strlen(str)-1 , false))
			printf("YES\n");
		else printf("NO\n");
	}
}