#include <cstdio>
#include <cmath>

#define ODD false
#define EVEN true

using namespace std;

int main()
{
	int Q , x , y , height_y , height_x , height_x1;
	long int N , ans;
	char query[3];
	bool red = ODD;

	scanf("%i" , &Q);

	while(Q--)
	{
		scanf("%s" , query);
		switch(query[1])
		{
			case 'i':
				red = !red;
				break;

			case 'b':
				scanf("%i%i" , &x , &y);
				
				height_y = (int) floor(log2(y));
				height_x = (int) floor(log2(x));
				height_x1 = height_x;
				
				if(x == y && ((red==EVEN && !(height_x%2)) || (red==ODD && (height_x%2))))
					{printf("0\n"); continue;}
				else if(x == y && ((red==EVEN && (height_x%2)) || (red==ODD && !(height_x%2))))
					{printf("1\n"); continue;}
					
				N = 0;
				
				if(height_y > height_x)
				{
					while(height_y != height_x)
						height_y--,N++ , y/=2;
					while(x != y)
						N += 2, height_y-- , x/=2 , y/=2;
				}
				else
				{
					while(height_x != height_y)
						height_x--,N++,x/=2;
					while(x != y)
						N += 2, height_x-- , x/=2 , y/=2;
				}
				N++;
				//printf("N(b): %li\n" , N);
				if(red == ODD && (height_x1 % 2))
					ans = N/2;
				else if (red == ODD && !(height_x1 % 2))
					if(N%2) ans = N/2 + 1;
					else ans = N/2;
				else if(!(height_x1 % 2)) ans = N/2; 
				else if(N%2) ans = N/2 + 1;
						else ans = N/2;
				
				printf("%li\n" , ans);
				break;

			case 'r':
				scanf("%i%i" , &x , &y);
				
				height_y = (int) floor(log2(y));
				height_x = (int) floor(log2(x));
				height_x1 = height_x;
				
				if(x == y && ((red==EVEN && (height_x%2)) || (red==ODD && !(height_x%2))))
					{printf("0\n"); continue;}
				else if(x == y && ((red==EVEN && !(height_x%2)) || (red==ODD && (height_x%2))))
					{printf("1\n"); continue;}
				
				N = 0;
				scanf("%i%i" , &x , &y);
				height_y = (int) floor(log2(y));
				height_x = (int) floor(log2(x));
				if(height_y > height_x)
				{
					while(height_y != height_x)
						height_y--,N++ , y/=2;
					while(x != y)
						N += 2, height_y-- , x/=2 , y/=2;
				}
				else
				{
					while(height_x != height_y)
						height_x--,N++ , x/=2;
					while(x != y)
						N += 2, height_x-- , x/=2 , y/=2;
				}
				N++;
				
				//printf("N(r): %li\n" , N);
				if(red == ODD && (height_x1 % 2))
					if(N%2) ans = N/2 + 1;
					else ans = N/2;
				else if (red == ODD && !(height_x1 % 2))
					{ans = N/2;}
				else if(!(height_x1 % 2))
					if(N%2) ans = N/2 + 1;
					else ans = N/2;
				else ans = N/2;
				
				printf("%li\n" , ans);
				break;
		}
	}
	return 0;
}