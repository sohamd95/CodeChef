#include <bits/stdc++.h>

#define ll long long int
#define MAX 10005
using namespace std;

typedef vector<int> VI;

VI v[MAX];
bool marked[MAX];
int parents[MAX];
int rlevel[MAX];
 
struct prod
{
	int city;
	int product;
};
prod prd[MAX];                                           //stores the product information
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//bool myfnc (prod i , prod j) { return (i.product<j.product); };
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dfs1(int n , int prev , int reclevel)
{
	marked[n]=true;
	parents[n]=prev;
	rlevel[n]=reclevel;
	
	prev=n;
	for(int i = 0 ; i < v[n].size(); i++)
	{
		if(!marked[v[n][i]])
		dfs1(v[n][i] , prev , reclevel+1);
 
	}	
};
 
int getanc(int x , int y)
{
	if(rlevel[x]>rlevel[y])
	{
		while(rlevel[x]!=rlevel[y])
		{
			x=parents[x];
		}
	}
	else if(rlevel[y]>rlevel[x])
	{
		while(rlevel[y]!=rlevel[x])
		{
			y=parents[y];
		}
	}
	
	
	while(x!=y)
	{
		x=parents[x];
		y=parents[y];
	}
	
	return x;
		
};
 
int getdistance(int x,int count)
{
	while(parents[x]!=-1)
	{
		count++;
		x=parents[x];
	}
	
	return count;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 
int main()
{
	//the saga begins
	int n , k;
	scanf("%d %d",&n,&k);
	int b;
	scanf("%d",&b);         //kings city
	b--;                    //to work in 0-index
	
	//clearing the vectors
	for(int i=0 ; i<MAX ;i++)
	v[i].clear();
	
	
	for(int i=0 ; i<n-1 ; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	//the graph is perfectly made
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	
 
	
	for(int i=0 ; i<n ;i++)
	{
		int j;
		scanf("%d" , &j);
		prd[i].city=i;
		prd[i].product=j;
	}
	
	//sort the product for range queries
	//sort(prd ,prd+n , myfnc);
	
	//////////////////////////////////////////////////////////////
	//setting the parents
	parents[b]=-1;
	dfs1(b, -1 , 0);
	//////////////////////////////////////////////////////////////
	int q;
	scanf("%d",&q);
	while(q--)
	{
		
		vector<int> remember;
		int a , p;
		scanf("%d %d",&a,&p);
		a--;
		
		//need to put p product cities in remember
		for(int i =0 ; i< n ; i++)
		{
			if(prd[i].product==p)
			remember.push_back(prd[i].city);
		}
	 
	    //for every remember city , we need to find min g(d)
	    int grandmax= -2;
	    int city=-1;
	    
	    for(int i=0 ; i<remember.size() ; i++)
	    {
	    	int desti = remember[i];
	    	int source = a;
	    	
	    	//string s1="",s2="";
	    	//setter(source,s1);
	    	//setter(desti,s2);
	    	
	    	int x = getanc(source , desti);
	    	//cout<<"ANCE: "<<x+1<<endl;
	        int count=0;
	        int gmin=getdistance(x,count);    //can be optimised
	        
	         
	        if(gmin == grandmax)
	    	{
	    		if(desti<city)
	    		city=desti;
	    	}
	    	if(gmin > grandmax)
	    	{
	    		grandmax = gmin;
	    		city = desti;
	    	}	
	    }

		if(city==-1)
		printf("%d\n" , city);
		else
		printf("%d\n" , city+1);		
	}	
} 