#include <cstdio>
#include <list>
#include <cstring>
#include <stack>
 
#ifndef INT_MAX
	#define INT_MAX 2147483647
#endif
 
using namespace std;
 
typedef list<int>::iterator adjlist_iterator;
 
class Graph
{
public:
	Graph(int _V): V(_V) , adjB(0)
	{
		VArray = new list <int> [_V];
		dist = new int[_V];
		memset(dist , 0 , sizeof(int)*_V);
		F = new int[_V];
		memset(F , 0 , sizeof(int)*_V);
		component = new int[_V + 1];
		memset(component , 0 , sizeof(int)*(_V + 1));
	}
 
	void connect(int , int);
	void disconnect(int);
	void update(int);
	void query(int , int , int);
 
	int V , adjB;
	list <int> *VArray;
	int *dist , *F , *component , **arr;
 
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

 	arr = new int * [adjB];
 	for(int i = 0 ; i<adjB ; i++)
 	{
 		arr[i] = new int [V+1];
 		memset(arr[i] , 0 , sizeof(int)*(V+1));
 	}

	adjlist_iterator it;
	stack <int> S;
	visited[b-1] = true;
	int curcomp = 0;
 
	while(VArray[b-1].size())
	{
		it = VArray[b-1].begin();
		S.push(*it) , dist[*it] = 1;
		VArray[*it].remove(b-1);
		VArray[b-1].remove(*it);

		curcomp++;
 
		int t;
	 
		while(!S.empty())
		{
			t = S.top();

			component[t+1] = curcomp;
			int *p = &arr[curcomp-1][F[t]];

			if(*p > 0)
				arr[curcomp-1][F[t]]++;
			else if(*p == 0)
				arr[curcomp-1][F[t]] = -1 * t;
			else
				arr[curcomp-1][F[t]] = 2;

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
	}
}
 
void Graph::query(int s , int p , int b)
{
	bool flg2 = false;

	if(component[s] == 0 || arr[component[s]-1][p] == 0)
		flg2 = true;
	else if(arr[component[s]-1][p] < 0)
	{
		printf("%i\n", ((-1*arr[component[s]-1][p]) + 1));
		return;
	}

	if(flg2)
	{
		bool flg = false;
		for(int i=0 ; i<V ; i++)
			if(F[i] == p)
			{
				printf("%i\n", i+1);
				flg = true;
				break;
			}
		if(!flg)
			printf("%i\n", -1);
		return;
	}
 
	stack<int> S;
	stack<int> D;
	bool flg = false;
	bool visited[V];
	memset(visited , false , V);
	S.push(s-1);
	D.push(dist[s-1]);
	int t , minDist = INT_MAX , minCity = INT_MAX , cityDist = 0 , ma = arr[component[s]-1][p];
 
	while(ma && !S.empty())
	{
		t = S.top();

		minDist = D.top();

		visited[t] = true;
		if(dist[t] < minDist)
			minDist = dist[t];
 
		if(F[t] == p)
		{
			ma--;
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
		bool flg = false;
		for(int i=0 ; i<V ; i++)
			if(F[i] == p)
			{
				printf("%i\n", i+1);
				flg = true;
				break;
			}
		if(!flg)
			printf("%i\n", -1);
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
		if(a == B || b == B)
			G.adjB++;
	}
 
	for(int i = 0 ; i<N2 ; i++)
	{
		scanf("%i" , &a);
		G.F[i] = a;
	}

	G.update(B);
//	for (int i = 0; i < G.V + 1; i++)
//	{
//		printf("%i,", G.component[i]);
//	}
//	printf("\n");

	scanf("%i" , &Q);
	int start , p;
 
	while(Q--)
	{
		scanf("%i%i" , &start , &p);
		G.query(start , p , B);
	}
 
	return 0;
} 