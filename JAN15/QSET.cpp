#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define lli long long int

using namespace std;

class SegmentTree
{
struct stNode;

public:
	SegmentTree(char *A)
	{
		siz = strlen(A);
		int w = 2*(int)pow(2,ceil(log(siz)/log(2)));
		memset(ST , 0 , sizeof(stNode*)*w);
		buildST(A , 1 , 1 , siz);
	}

	void update(int , int);
	lli query(int , int);
	
private:

	struct stNode
	{
		stNode(int _k = -1)
		{
			for(int i = 0 ; i<3 ; i++)
				rem[i] = 0;

			tot = (_k == -1)? 0 : (_k % 3);
			rem[tot] = (_k == -1)? 0 : 1;
		};

		lli rem[3];
		lli tot;
	};

	void updateUtil(int , int , int , int , int);
	stNode * queryUtil(int , int , int , int , int);
	void buildST(char *, int , int , int);
	stNode * merge(stNode *, stNode *);
	lli calc(stNode *);

	stNode *ST[262144];
	int siz;
};

SegmentTree::stNode* SegmentTree::queryUtil(int node , int qs , int qe , int ss , int se)
{
	if(ss > se || qs > se || qe < ss) return 0;

	if(qs <= ss && qe >= se)
		return ST[node];

	return merge(queryUtil(2*node , qs , qe , ss , (ss+se)/2) , queryUtil(2*node + 1 , qs , qe , ((ss+se)/2)+1 , se ));
}

lli SegmentTree::query(int qs , int qe)
{
	return calc(queryUtil(1 , qs , qe , 1 , siz));
}

void SegmentTree::buildST(char *A, int node , int ss , int se)
{
	if(ss > se)
		return;

	if(ss == se)
	{
		ST[node] = new stNode(A[ss-1]-'0');
		return;
	}

	buildST(A, 2*node , ss , (ss+se)/2);
	buildST(A , 2*node + 1, ((ss+se)/2) + 1 , se);

	ST[node] = merge(ST[2*node] , ST[2*node + 1]);
}

SegmentTree::stNode* SegmentTree::merge(stNode* l , stNode* r)
{
	if(!l && !r) return 0;
	else if(!l) return r;
	else if(!r) return l;

	SegmentTree::stNode *N = new stNode();

    N->tot = (l->tot + r->tot) % 3;
    for(int i = 0; i < 3; i++)
    {
        N->rem[i] += l->rem[i];
        N->rem[(i + l->tot) % 3] += r->rem[i];	//shifted by l->tot
    }
    return N;
}

lli SegmentTree::calc(stNode *n)
{
	if(!n) return 0;
	lli res = 0;
    for(int i = 0; i < 3; i++)
    {
        lli cur = n->rem[i];

        if(!i) cur++;
        res += (cur*(cur - 1))/2; // nC2
    }
    return res;
}

void SegmentTree::update(int pos , int key)
{
	updateUtil(1 , 1 , siz , pos , key);
}

void SegmentTree::updateUtil(int node, int l, int r, int pos, int key)
{
	if (l == r)
        ST[node] = new stNode(key);

    else
    {
        int mid = (l + r) / 2;
        if (pos <= mid)
            updateUtil(2*node , l, mid, pos, key);
        else
            updateUtil(2*node + 1, mid + 1, r, pos, key);

        ST[node] = merge(ST[2*node], ST[2*node + 1]);
    }
}

int main()
{
	int N,M,len,R,L,qtype;
	char A[100000];

	scanf("%i%i%s" , &N , &M , A);
	len = strlen(A);

	SegmentTree tree(A);

	while(M--)
	{
		scanf("%i%i%i" , &qtype , &R, &L);

		if(qtype == 1)
			tree.update(R , L);
		else
			printf("%lli\n", tree.query(R , L));
	}

	return 0;
}