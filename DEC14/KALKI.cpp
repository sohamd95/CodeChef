#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
 
using namespace std;
 
class UF
{
    int *id, cnt, *sz;
public:
	// Create an empty union find data structure with N isolated sets.
    UF(int N)   {
        cnt = N;
	id = new int[N];
	sz = new int[N];
        for(int i=0; i<N; i++)	{
            id[i] = i;
	    sz[i] = 1;
	}
    }
    ~UF()	{
	delete [] id;
	delete [] sz;
    }
	// Return the id of component corresponding to object p.
    int find(int p)	{
        int root = p;
        while (root != id[root])
            root = id[root];
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
 
    bool inSameSet(int x , int y)
    {
    	return find(x) == find(y);
    }
	// Replace sets containing x and y with their union.
    void merge(int x, int y)	{
        int i = find(x);
        int j = find(y);
        if (i == j) return;
		
		// make smaller root point to larger one
        if   (sz[i] < sz[j])	{ 
		id[i] = j; 
		sz[j] += sz[i]; 
	} else	{ 
		id[j] = i; 
		sz[i] += sz[j]; 
	}
        cnt--;
    }
 
	// Return the number of disjoint sets.
    int count() {
        return cnt;
    }
};
 
struct edge
{
	edge(int a , int b , int _w): d1(a),d2(b),w(_w){}
	int d1;
	int d2;
	double w;
};
 
struct Compare
{
	bool operator () (const edge & a , const edge & b)
	{
		return (a.w > b.w);
	}
};
 
typedef priority_queue <edge , vector<edge> , Compare> Heap;
 
int main()
{
	int T , N , N2, x , y;
	double wt;
	vector <pair <int,int> > V;
 
	scanf("%i" , &T);
 
	while(T--)
	{
		V.clear();
		scanf("%i" , &N);

		N2 = N;
		
		while(N2--)
		{
			scanf("%i%i" , &x , &y);
			V.push_back(pair<int,int>(x,y));
		}

		Heap H;
 
		for(int i = 0 ; i<N ; i++)
			for(int j = i+1 ; j<N ; j++)
			{
				wt = sqrt(pow((V[j].first - V[i].first),2) + pow((V[j].second - V[i].second),2));
				H.push(edge(i,j,wt));
			}
	
		UF S(N);
 
		while(S.count() != 1)
		{
			edge e = H.top();
			if(!S.inSameSet(e.d1 , e.d2))
			{
				S.merge(e.d1 , e.d2);
				printf("%i %i\n", e.d1+1 , e.d2+1);
			}
			H.pop();
		}
	}
 
	return 0;
}  