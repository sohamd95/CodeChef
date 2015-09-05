#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
#define SIZ 20

using namespace std;

struct descSort
{
	bool operator() (int a , int b)
	{
		return (a > b);
	}
}Comp;

int main()
{
	int T, N, K;
	vector<bitset<SIZ> > V;
	vector<int> nums;

	scanf("%i" , &T);

	while(T--)
	{
		V.clear();
		nums.clear();

		scanf("%i%i" , &N , &K);
		bitset <SIZ> bK(K);
		int _num;

		for(int i = 0 ; i<N ; i++)
		{
			scanf("%i" , &_num);
			nums.push_back(_num);
		}

		std::sort(nums.begin() , nums.end() , Comp);

		if(nums[0] == 1)
		{
			if(K%2)
				printf("%i\n", K);
			else printf("%i\n", K+1);
			continue;
		}

		int k = 0;
		while(k < N)
		{
			bitset <SIZ> bstemp(nums[k++]);
			V.push_back(bstemp);
		}

		int l = SIZ , cur = 0;

		while(!V[cur][--l]);

		while(l != -1 && cur < N)
		{
			if(!V[cur][l])
			{
				//pivoting
				bool flg = false;
				for(int j=cur+1 ; j<N ; j++)
				{
					if(V[j][l])
					{
						int tmp = V[j].to_ulong();
						bitset <SIZ> bt(tmp);
						V[j] = V[cur];
						V[cur] = bt;
						flg = true;
						break;
					}
				}
				if(!flg)
					l--;
			}
			else
			{
				for(int j = cur+1 ; j<N ; j++)
					if(V[j][l])
						V[j] ^= V[cur];
				cur++;
				l--;
			}
		}
/***************************************************************************************/

		int msp2 = SIZ, cur2 = 0;

		while(!V[0][--msp2]);
		
		for(int j = 0 ; j<N ; j++)
		{
			bitset <SIZ> bstemp = bK;
			bstemp ^= V[j];
			if(bstemp.to_ulong() > bK.to_ulong())
				bK = bstemp;
		}

//		for(int j = 0 ; j<N ; j++)
//		{
//			printf("%u," , V[j].to_ulong());
//		}

		printf("%u\n" , bK.to_ulong());
	}

	return 0;
}
