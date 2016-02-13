#include <iostream>  
#include "MGraph.cpp"
using namespace std;  

int main()  
{  
    MGraph<char,int> G;  
    G.CreateGraph();  
    G.CheckCircle();  
    system("pause");  
    return 1;  
} 