#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned long long int ulli;

class Polygon {

public:

	Polygon(int vertices , int *X , int *Y) {
		this->vertices = vertices;
		this->X = X;
		this->Y = Y;
		area = calcArea(this);
	}

	int id;
	int vertices;
	int *X , *Y;
	double area;

private:
	static double calcArea(Polygon *p) {
		
		double area = 0;

		for(int i = 0 ; i < p->vertices-1 ; i++) {
			area += p->X[i] * (double)p->Y[i+1];
			area -= p->X[i+1] * (double)p->Y[i];
		}
		area += p->X[p->vertices-1] * (double)p->Y[0];
		area -= (p->X[0] * (double)p->Y[p->vertices-1]);

		return (abs(area)/2.0);
	}
};

struct compFuncObj {

	bool operator () (const Polygon *a , const Polygon *b) {
		return (a->area < b->area);
	}

} SortByArea;

int main() {

	int T , N , Mi , *X , *Y;
	scanf("%i" , &T);
	vector<Polygon*> polygons;
	vector<int> answer;

	while(T--) {
		scanf("%i" , &N);
		polygons.resize(N);
		answer.resize(N);

		for(int i = 0 ; i < N ; i++) {
			scanf("%i" , &Mi);
			X = new int[Mi];
			Y = new int[Mi];

			for (int j = 0 ; j < Mi ; j++)
				scanf("%i%i" , &X[j] , &Y[j]);

			polygons[i] = new Polygon(Mi , X , Y);
			polygons[i]->id = i;
		}

		std::sort(polygons.begin() , polygons.end() , SortByArea);
		
		for(int i = 0 ; i < N ; i++) {
			answer[polygons[i]->id] = i;
		}
		for(int i = 0 ; i < N ; i++) {
			printf("%i ", answer[i]);
		}
		printf("\n");
	}
	return 0;
}