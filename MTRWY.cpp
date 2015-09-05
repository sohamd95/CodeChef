#include <iostream>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

struct query
{
	query(int type , int x1 = 0 , int y1 = 0 , int x2 = 0  , int y2 = 0)
	{
		this->type = type;

		switch(type)
		{
			case 1:
				params = new int[2];
				params[0] = x1;
				params[1] = y1;
				break;

			case 2:
				params = new int[2];
				params[0] = x1;
				params[1] = y1;
				break;

			case 3:
				params = new int[4];
				params[0] = x1;
				params[1] = y1;
				params[2] = x2;
				params[3] = y2;
				break;

			case 4:
				break;
		}
	}

	int type;
	int *params;
};

class disjointSets
{
public:

	reConstruct(int N)
	{
		this->N = N;
		largestComponentSize = 1;
		root.clear();
		rank.clear();
		siz.clear();
		root.resize(N , 0);
		rank.resize(N , 0);
		siz.resize(N , 1);
	};

	int getLargestComponentSize()
	{
		return largestComponentSize;
	}

	int find(int i)
	{
		if(root[i] == i)
			return i;
		else 
			root[i] = find(root[i]);
		return root[i];
	}

	void unite(int i , int j)
	{
		int iroot = find(i);
		int jroot = find(j);

		if(iroot == jroot)
			return;

		if(rank[iroot] < rank[jroot])
		{
			root[iroot] = jroot;
			siz[jroot] += siz[iroot];
			if(largestComponentSize < siz[jroot])
				largestComponentSize = siz[jroot];
		}
		else if(rank[iroot] > rank[jroot])
		{
			root[jroot] = iroot;
			siz[iroot] += siz[jroot];
			if(largestComponentSize < siz[iroot])
				largestComponentSize = siz[iroot];
		}
		else
		{
			root[iroot] = jroot;
			siz[jroot] += siz[iroot];
			rank[jroot]++;
			if(largestComponentSize < siz[jroot])
				largestComponentSize = siz[jroot];
		}
	}

private:

	int N;
	int largestComponentSize;
	std::vector<int> root;
	std::vector<int> rank;
	std::vector<int> siz;
};

bool operator ==(const query &a  , const query &b)
{
	if(a.type != b.type)
		return false;

	if(a.params[0] == b.params[0])
		return (a.params[1] == b.params[1]);
	else return false;

}
bool operator <(const query &a  , const query &b)
{
	if(a.params[0] < b.params[0])
		return true;
	else return false;
}
bool operator >(const query &a  , const query &b)
{
	if(a.params[0] > b.params[0])
		return true;
	else return false;
}

int inSameComponent(int a , int b , disjointSets S)
{
	return ((S.find(a) == S.find(b))?1:0);
}

int main()
{
	ios::sync_with_stdio(false);

	int T , N , M , Q , type , x1 , y1 , x2 , y2 , ans;
	disjointSets S;
	std::vector< query > queries;
	set < query > seen;
	std::vector<query>::reverse_iterator it;

	cin >> T;

	while(T--)
	{
		cin >> N >> M >> Q;
		S.reConstruct(N*M);
		seen.clear();
		queries.clear();
		ans = 0;

		while(Q--)
		{
			cin >> type;
			query *q;

			switch(type)
			{
				case 1:
					cin >> x1 >> y1;
					q = new query(type , x1 , y1);
					if(seen.find(*q) == seen.end())
					{
						queries.push_back(*q);
						seen.insert(*q);
					}
					break;

				case 2:
					cin >> x1 >> y1;
					q = new query(type , x1 , y1);
					if(seen.find(*q) == seen.end())
					{
						queries.push_back(*q);
						seen.insert(*q);
					}
					break;

				case 3:
					cin >> x1 >> y1 >> x2 >> y2;
					q = new query(type , x1 , y1 , x2 , y2);
					queries.push_back(*q);
					break;

				case 4:
					q = new query(type);
					queries.push_back(*q);
					break;
			}
		}

		it = queries.rbegin();
		while(it != queries.rend())
		{
			switch((*it).type)
			{
				case 1:
					break;
				case 2:
					break;
				case 3:
					ans += inSameComponent((*it).params[0] , (*it).params[1] , S);
					break;
				case 4:
					ans += S.getLargestComponentSize();
					break;
			}
			it++;
		}
		cout << ans << endl;
	}

	return 0;
}