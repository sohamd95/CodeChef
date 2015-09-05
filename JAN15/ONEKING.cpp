#include <cstdio>
#include <vector>

struct intv
{
	intv(int _ss , int _se):ss(_ss) , se(_se){}
	int ss , se;
};

using namespace std;

int main()
{
	int T , N , ss , se;
	bool flg;
	vector <intv> V;

	scanf("%i" , &T);

	while(T--)
	{
		//printf("RUN%i\n",T);
		V.clear();
		scanf("%i" , &N);
		scanf("%i%i" , &ss , &se);
		V.push_back(intv(ss,se));

		for(int i = 1 ; i<N ; i++)
		{
			flg = false;
			scanf("%i%i" , &ss , &se);

			for(int j=0 ; j<V.size() ; j++)
			{
				if(ss < V[j].ss && se > V[j].se) {flg = true;break;}
				else if((ss >= V[j].ss && ss <= V[j].se) || (se <= V[j].se && se >= V[j].ss))
				{
					if(V[j].ss < ss)V[j].ss = ss;
					if(V[j].se > se)V[j].se = se;
					flg = true;
					break;
				}
			}

			if(!flg)
				V.push_back(intv(ss,se));
		}

		printf("%i\n", V.size());
	}
	return 0;
}