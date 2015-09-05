#include <cstdio>
#include <list>
#include <cstring>
#include <map>
#include <stack>
 
#ifndef INT_MAX
	#define INT_MAX 2147483647
#endif
 
using namespace std;

typedef list<int>::iterator adjlist_iterator;
 
class Graph
{
public:
	Graph(int _V): V(_V)
	{
		VArray = new list <int> [_V];
		dist = new int[_V];
		F = new int[_V];
	}
 
	void connect(int , int);
	void disconnect(int);
	void update(int);
	void query(int , int , int);
 
	int V , *dist , *F;
	list <int> *VArray;
	map <int,int> M;
};
 
void Graph::connect(int a , int b)
{
	VArray[a-1].push_back(b-1);
	VArray[b-1].push_back(a-1);
}
 
void Graph::disconnect(int a)
{
	adjlist_iterator it = VArray[a-1].begin();
	while(it != VArray[a-1].end())
	{
		VArray[*it].remove(a-1);
		++it;
	}
	VArray[a-1].clear();
}
 
void Graph::update(int b)
{
	bool visited[V];
	memset(visited , false , V);
 
	adjlist_iterator it = VArray[b-1].begin();
	stack <int> S;

	S.push(b-1);
	dist[b-1] = 0;
 
	int t;
 
	while(!S.empty())
	{
		t = S.top();
		visited[t] = true;
		S.pop();
		adjlist_iterator it2 = VArray[t].begin();
		while(it2 != VArray[t].end())
		{
			if(!visited[*it2])
			{
				dist[*it2] = dist[t]+1;
				S.push(*it2);
			}
			it2++;
		}
	}

	for(int i = 0 ; i<V ; i++)
	{
		if(M.find(F[i]) == M.end())
		{
			M[F[i]] = i+1;
		}
	}
}
 
void Graph::query(int s , int p , int b)
{
	if(s == b)
	{
		if(M.find(p) == M.end())
			printf("-1\n");
		else printf("%i\n", M[p]);
		return;
	}
 
	stack<int> S;
	stack<int> D;
	bool visited[V];
	memset(visited , false , V);
	S.push(s-1);
	D.push(dist[s-1]);
	int t , minDist = INT_MAX , minCity = INT_MAX , cityDist = 0;
 
	while(!S.empty())
	{
		t = S.top();
 		minDist = D.top();
 
		visited[t] = true;
		if(dist[t] < minDist)
			minDist = dist[t];
 
		if(F[t] == p)
		{
			if(cityDist < minDist)
			{
				minCity = t;
				cityDist = minDist;
			}
			else if(cityDist == minDist && minCity > t)
				minCity = t;
		}
 
		S.pop();
		D.pop();
		adjlist_iterator it = VArray[t].begin();
 
		while(it != VArray[t].end())
		{
			if(!visited[*it] && dist[*it] > cityDist)
			{
				S.push(*it);
				D.push(minDist);
			}
			it++;
		}
	}
 
	if(minCity == INT_MAX)
	{
		if(M.find(p) == M.end())
			printf("-1\n");
		else printf("%i\n", M[p]);
		return;
	}
	else printf("%i\n", minCity + 1);
}
 
int main()
{
	int N , N2 , K , B , Q , a , b;

	scanf("%i%i%i" , &N , &K , &B);
	N2 = N;
 
	Graph G(N);
 
	while(--N)
	{
		scanf("%i%i" , &a , &b);
		G.connect(a , b);
	}
 
	for(int i = 0 ; i<N2 ; i++)
	{
		scanf("%i" , &a);
		G.F[i] = a;
	}

	G.update(B);
	G.disconnect(B);
 
	scanf("%i" , &Q);
	int start , p;
 
	while(Q--)
	{
		scanf("%i%i" , &start , &p);
		G.query(start , p , B);
	}
 
	return 0;
}   