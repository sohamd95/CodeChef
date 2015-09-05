#include <iostream>
#include <stack>
#include <string>

int main()
{
	stack <char> s;
	string str;
	int T , len , maxlen , i;

	cin >> T;

	while(T--)
	{
		cin >> str;
		len = 0, maxlen = 0;
		while(!s.empty())
			s.pop();

		for(i = 0 ; i<str.length() ; i++)
		{
			if(str[i] == '<')
				s.push(str[i]) , len++;
			else if(!s.empty())
				{
					len++; 
					s.pop();
				}
			else
			{
				maxlen = (maxlen < len)? len : maxlen;
				len = 0;
			}
		}
		if(!s.empty()) len -= s.size();

		cout << maxlen <<endl;
	}
	return 0;
}