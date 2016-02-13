#include <iostream>
#include <stdio.h>   
#include <stdlib.h>   
using namespace std;

#define INFINITY INT_MAX   
  
typedef struct   
{  
    int source;  
    int dest;  
    int weight;  
}Edge;  
  
void BellmanFord(Edge edges[], int edgecount, int nodecount, int source);  
  
int main()  
{  
    /* This test case should produce the distances 2, 4, 7, -2, and 0. */  
    Edge edges[10] = {{0, 1, 5}, {0, 2, 8}, {0, 3, -4}, {1, 0, -2},  
                      {2, 1, -3}, {2, 3, 9}, {3, 1, 7}, {3, 4, 2},  
                      {4, 0, 6}, {4, 2, 7}};  
    BellmanFord(edges, 10, 5, 4);  
    return 0;  
}  

void BellmanFord(Edge edges[], int edgecount, int nodecount, int source)  
{  
    int *distance = (int*)malloc(nodecount*sizeof(int));  
    int i, j;  
  
    for(i = 0; i < nodecount; ++i)  
		distance[i] = INFINITY;  
    distance[source] = 0;  
  
    for(i = 0; i < nodecount; ++i)   
    {  
       int nbChanges = 0;   
       for(j = 0; j < edgecount; ++j)   
       {  
            if(distance[edges[j].source] != INFINITY)   
            {  
				int new_distance = distance[edges[j].source] + edges[j].weight;  
                if(new_distance < distance[edges[j].dest])   
                {  
					distance[edges[j].dest] = new_distance;  
					nbChanges++;   
                }   
			}  
		}  
         // if one iteration had no impact, further iterations will have no impact either   
		if(nbChanges == 0) 
			break;   
    }  
  
    for(i = 0; i < edgecount; ++i)   
    {  
        if(distance[edges[i].dest] > distance[edges[i].source] + edges[i].weight)   
        {  
			cout << "Negative edge weight cycles detected!" << endl;  
            free(distance);  
            return;  
		}  
    }  
  
	cout << "The shortest distance between nodes: " << endl;
    for(i = 0; i < nodecount; ++i)     
		cout << source << " -> " << i << " : " << distance[i] << endl;

    free(distance);  
    return;  
}  