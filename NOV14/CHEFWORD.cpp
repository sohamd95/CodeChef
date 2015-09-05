#include <iostream>
#include <cstring>
#include <string>
#include <set>

using namespace std;
     
class Graph
{
public:
    virtual void connect(int = -1 , int = -1 , double = 0) =0 ;
    void showAdjList() const;

protected:
    double **weights;
};

//Dervied Class: Directed Graph
class DirectedGraph : public Graph
{
public:
    DirectedGraph(int V = 26)
    {
        weights = new double * [V];
         
        for(int i = 0 ; i < V ; i++)
        {
            weights[i] = new double [V];
            memset(weights[i] , 0 , sizeof(double)*26);
        }
    }
    void connect(int , int , double = 0);
    double probOf(char , char);
    void exponetiate(int);
    void showWeightMatrix();
    void clear();
};
     
void DirectedGraph::connect(int V1, int V2 , double pi)
{
    weights[V1][V2] = pi;
}

double Mult(double A[26][26] , double B[26][26] , int row , int col)
{
    double res = 0;
    for(int i=0 ; i<26 ; i++)
        res += A[row][i] * B[i][col];
    return res;
}

void DirectedGraph::exponetiate(int exp)
{
    if(!exp || exp == 1) return;

    if(exp == 2)
    {
        //Make a copy of current wt matrix
        double temp[26][26];

        for(int i = 0 ; i<26 ; i++)
            for(int j = 0 ; j<26 ; j++)
                temp[i][j] = weights[i][j];

        //Square weight matrix
        for(int i = 0 ; i<26 ; i++)
            for(int j = 0 ; j<26 ; j++)
                weights[i][j] = Mult(temp , temp , i , j);
    }
    else if(!(exp % 2)) //if exp is even
    {
        exponetiate(exp/2); //Exponetiate to exp / 2

        //Make a copy of current wt matrix
        double temp[26][26];

        for(int i = 0 ; i<26 ; i++)
            for(int j = 0 ; j<26 ; j++)
                temp[i][j] = weights[i][j];

        //Square weight matrix
        for(int i = 0 ; i<26 ; i++)
            for(int j = 0 ; j<26 ; j++)
                weights[i][j] = Mult(temp , temp , i , j);
    }
    else if(exp % 2)//exp is Odd
    {
        //Make a copy of current wt matrix
        double temp[26][26] , temp2[26][26];

        for(int i = 0 ; i<26 ; i++)
            for(int j = 0  ;j<26 ; j++)
                temp[i][j] = weights[i][j];

        //exponentiate to exp-1
        exponetiate(exp-1);

        //Multiply with temp1
        for(int i = 0 ; i<26 ; i++)
            for(int j = 0 ; j<26 ; j++)
                temp2[i][j] = weights[i][j];

        for(int i = 0 ; i<26 ; i++)
            for(int j = 0 ; j<26 ; j++)
                weights[i][j] = Mult(temp , temp2 , i , j);
    }
}

void DirectedGraph::clear()
{
	for(int i = 0 ; i <26 ; i++)
		memset(weights[i] , 0 , 26*sizeof(double));
}

double DirectedGraph::probOf(char ch , char ch2)
{
    return (weights[ch-'a'][ch2-'a']);
}

void DirectedGraph::showWeightMatrix()
{
    cout << endl;
    for(int i = 0 ; i<10 ; i++)
    {
        for(int j = 0 ; j<5 ; j++)
            cout << weights[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int T , N , K , len;
    double prob , word_prob , pi;
    string str , word , temp;
    set <string> words;
    DirectedGraph G;

    cin >> T;
     
    while(T--)
    {
        G.clear();
        words.clear();
        prob = 0;
        cin >> N >> K >> str;
        len = str.length();

        for(int i = 0 ; i<26 ; i++)
            for(int j = 0 ; j<26 ; j++)
            {
                cin >> pi;
                G.connect(i,j,pi);
            }
            
        G.exponetiate(K);

        while(N--)
        {
            cin >> word;
            if(word.length() == len)
                words.insert(word);
        }

        for(set<string>::iterator it = words.begin() ; it != words.end() ; it++)
        {
            temp = *it;
            word_prob = 1;

            for(int i = 0 ; i<len ; i++)
                word_prob *= G.probOf(str[i] , temp[i]);

            prob += word_prob;
        }
        cout << prob << endl;
    }
    return 0;
}