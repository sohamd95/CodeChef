#include <cstring>
#include <iostream>
#define INT_M 2147483647

inline int min(int x, int y, int z)
{
    if (x < y)
        return x < z ? x : z;
    else
        return y < z ? y : z;
}

inline void swap(int *& A , int *& B)
{
    int * T = A;
    A = B;
    B = T;
}

int Levenshtein_distance(const char* str1 , const char* str2 , const short int cost_a , const short int cost_b , const short int k)
{
    if(k == 0) return -1;

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if(len1 == len2)
        if (!strcmp(str1 , str2))    return 0;
    if (cost_a == 0 && cost_b == 0) return 0;
    if (len2 - len1 > k) return -1;
    if (len1 - len2 > k) return -1;

    int * PrevRow = new int[len2 + 1];
    int * CurrentRow = new int[len2 + 1];
    int rowMin = INT_M;

    for (int i = 0 ; i <= len2 ; i++)
        PrevRow[i] = i;

    for (int i = 0 ; i < len1 ; i++)
    {
        CurrentRow[0] = i + 1;

        for (int j = 0 ; j < len2 ; j++)
        {           
            CurrentRow[j+1] = min( (CurrentRow[j] + cost_a),
                                    (PrevRow[j + 1] + cost_a),
                                    (PrevRow[j] + (str1[i] == str2[j] ? 0 : cost_b))
                                );
            //cout << CurrentRow[j+1] << ","; 
            if(rowMin > CurrentRow[j+1]) rowMin = CurrentRow[j+1];
        }
        //cout << "|" << rowMin << endl <<endl;
        if(rowMin > k) return -1;
        rowMin = INT_M;
        swap(CurrentRow , PrevRow);
    }
        
    return PrevRow[len2];
}

int main()
{
	std::ios::sync_with_stdio(false);

	short int T , a , b , k;
	int cost;
	char s[100000] , w[100000];

	std::cin >> T;

	while(T--)
	{
		std::cin >> s >> w >> a >> b >> k;
		int cost = Levenshtein_distance(s , w , a , b , k) ;
        if(cost <= k) std::cout << cost << "\n" ;
        else std::cout << -1 << "\n" ;
	}

	return 0;
}