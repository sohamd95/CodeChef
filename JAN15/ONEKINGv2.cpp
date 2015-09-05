#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct intv
{
	intv(int _ss , int _se):ss(_ss) , se(_se){}
	int ss , se;
};

struct Compare
{
	bool operator () (const intv &a , const intv &b)
	{
		return (a.ss < b.ss);
	}
}Comp;

int main()
{
	int T , N , ss , se;
	bool flg;
	vector <intv> V;
	stack <intv> S;

	scanf("%i" , &T);

	while(T--)
	{
		//printf("RUN%i\n",T);
		V.clear();
		while(!S.empty())
			S.pop();
		scanf("%i" , &N);

		for(int i = 0 ; i<N ; i++)
		{
			scanf("%i%i" , &ss , &se);
			V.push_back(intv(ss,se));
		}

		std::sort(V.begin() , V.end() , Comp);
		S.push(V[0]);

		for(int i = 1 ; i<N ; i++)
		{
			if(V[i].ss <= S.top().ss && V[i].se >= S.top().se)
				continue;
			else if((V[i].ss >= S.top().ss && V[i].ss <= S.top().se) || (V[i].se <= S.top().se && V[i].se >= S.top().ss))
				{
					if(S.top().ss < V[i].ss)S.top().ss = V[i].ss;
					if(S.top().se > V[i].se)S.top().se = V[i].se;
				}
			else S.push(V[i]);
		}

		printf("%i\n", S.size());
	}
	return 0;
}