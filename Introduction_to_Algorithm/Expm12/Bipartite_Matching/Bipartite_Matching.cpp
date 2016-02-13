#include <iostream>
#include <memory.h>
using namespace std;
#define MAX 102

long n, n1, match;		//n1, n2 indicates number of constraints in set 1 and number of nodes in set 2
long adj[MAX][MAX];		//
long mat[MAX];		//record match of nodes
bool used[MAX];		//if is matched
FILE *file_in, *file_out;

void readfile();
bool crosspath(long k);
void hungaryMatch();
void print();

int main()
{
    readfile();
    hungaryMatch();
    print();
    return 0;
}

void readfile()
{
    file_in = fopen("flyer_in", "r");
    //file_out = fopen("flyer_out", "w");
    fscanf(file_in, "%ld %ld", &n, &n1);
    long a,b;
    while(fscanf(file_in, "%ld %ld", &a, &b) != EOF)
        adj[a][ ++adj[a][0] ] = b;
    match = 0;
}

bool crosspath(long k)
{
    for(long i = 1; i <= adj[k][0]; i++)
    {
        long j = adj[k][i];
        if(!used[j])
        {
            used[j] = true;
            if(mat[j] == 0 || crosspath(mat[j]))
            {
                mat[j] = k;
                return true;
            }
        }
    }
    return false;
}

void hungaryMatch()
{
    for(long i = 1; i <= n1; i++)
    {
        if(crosspath(i))
			match++;
        memset(used, 0, sizeof(used));
    }
}

void print()
{
    //fprintf(file_out, "%ld", match);
    cout << "The max number of perfect match is: " << match << endl;
	fclose(file_in);
    //fclose(file_out);
	
}

