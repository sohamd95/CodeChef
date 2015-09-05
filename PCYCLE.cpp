#include <iostream>
#include <queue>
using namespace std;

int main()
{
	short int N  , *Arr;

	cin >> N;
	Arr = new short int [N+1];

	for(int i = 1 ; i <= N ; i++)
		cin >> Arr[i];

	short int init , cur = 1 , pre = 0 , k = 0;
	int N2 = N;
	queue <int> q , q2;

	while(N)
	{
		init = 1;
		while(Arr[init] == -1 && init <= N2)
			init++;
		q.push(init);
		cur = init;

		do
		{
			//cout << "*" << cur <<"*" << endl;
			q.push(Arr[cur]);
			pre = cur;
			cur = Arr[cur];
			Arr[pre] = -1;
			N--;
		}
		while(cur != init);
	}

	int init2 = q.front() , c=0;
	q2.push(q.front());
	q.pop();
	while(!q.empty())
	{
		if(q.front() == init2)
		{
			c++;
			q2.push(q.front());
			q.pop();
			init2 = q.front();
			if(!q.empty())
				{q2.push(q.front()); q.pop();}
		}
		else
		{
			q2.push(q.front());
			q.pop();
		}
	}

	cout << c << endl;

	init2 = q2.front();
	cout << init2 << " ";
	q2.pop();

	while(!q2.empty())
	{
		if(q2.front() == init2)
		{
			cout << q2.front() << endl;
			q2.pop();
				init2 = q2.front();
			if(!q2.empty())
			{
				cout << q2.front() << " ";
				q2.pop();
			}
		}
		else
		{
			cout << q2.front() << " ";
			q2.pop();
		}
	}
	return 0;
}