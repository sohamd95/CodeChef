#include <iostream>
#include <map>
#include <list>
#include <cstring>
#include <string>

using namespace std;

struct node
{
	node(string _city , int _cost):city(_city),cost(_cost){}
	string city;
	int cost;
};

typedef list<node>::iterator adjlist_iterator;

class Graph
{
public:
	Graph(int N):v(N),c(0)
	{
		VerticesArray = new list <node> [N];
		inDegree = new int[N];
		memset(inDegree , 0 , N * sizeof(int));
	}
	void connect(string , string , short int);
	void print(int *);
	void DFT();

private:
	void DFT(int , bool* , string , int);
	list <node> *VerticesArray;
	map <string , int> M;
	map <int , string> M2;
	int v , c , *inDegree , *outDegree , **weights;
};

void Graph::connect(string A , string B , short int C)
{
	if(M.find(A) == M.end())
		{M[A] = c++; M2[c-1] = A;}
	if(M.find(B) == M.end())
		{M[B] = c++; M2[c-1] = B;}

	int a = M[A];
	int b = M[B];

	node N(B,C);
	VerticesArray[a].push_back(N);
	inDegree[b]++;
}

void Graph::DFT()
{
	bool visited[v];
	memset(visited , false , v);
	int V;
	
	for(V = 0 ; V<v ; V++)
		if(inDegree[V] == 0)
			break;
	
//	for(int j = 0 ; j<v ; j++)
	//	cout << inDegree[j] << ",";
//	cout << M2[V] << "/";
			
	DFT(V , visited , "*" , -1);
}

void Graph::DFT(int V , bool *visited , string prev , int cst)
{
	//cout << V <<",";
	adjlist_iterator it = VerticesArray[V].begin();
	visited[V] = true;
	if(prev != "*")
		cout << prev << " " << M2[V] << " " << cst << "$\n";
	prev = M2[V];

	for( ; it != VerticesArray[V].end() ; it++)
		if(!visited[M[it->city]])
			DFT(M[it->city] , visited , prev , it->cost);
}

int main()
{
	short int T , N , cost;
	string A , B;
	char t1[51] , t2[51] , c;

	cin >> T;
	Graph *G;

	while(T--)
	{
		cin >> N;
		G = new Graph(N);
		N--;
		int total = 0;

		while(N--)
		{
			cin >> t1 >> t2 >> cost >> c;
			A = t1;	B = t2; total += cost;

			G->connect(A,B,cost);
		}
		G->DFT();
		cout << total << "$" << endl;
	}
	return 0;
}