#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
	short int T;
	char str[100001];
	int prev_index[26] , max_len , cur_len , i;

	scanf("%hi" , &T);

	while(T--)
	{
		for(i = 0 ; i<26 ; i++)
			prev_index[i] = -1;
		max_len = 1;
		cur_len = 1;

		scanf("%s" , str);

		prev_index[str[0] - 'a'] = 0;
		
		for(i = 1 ; i<strlen(str); i++)
		{
			int pi = prev_index[str[i] - 'a'];
			
			if(pi == -1 || (pi < i-cur_len))
				{cur_len++;}
			else
			{
				if(max_len < cur_len)
					max_len = cur_len;
				cur_len = i - pi;
			}
			prev_index[str[i] - 'a'] = i;
		}
		if (cur_len > max_len)
    		max_len = cur_len;
    		
		printf("%i\n", max_len);
	}
	return 0;
}