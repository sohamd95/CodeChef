#include <cstdio>

using namespace std;

int main()
{
	int T , x , y , moves;
	scanf("%i" , &T);
	while(T--)
	{
		scanf("%i%i" , &x , &y);
		x = abs(x);
		y = abs(y);
		if(x>y)
			moves = (2*x + (x-y)%2) ;
		else
			moves = (2*y - (y-x)%2);

		printf("%i\n", moves);
	}
	return 0;
}