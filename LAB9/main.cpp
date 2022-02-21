

#include<iostream>
#include<stdlib.h>
#include "Graph.h"

using namespace std;

int main()
{

   
    int n = 10;
     int** A = new int* [n];
   
   
    for(int i = 0; i < n; ++i)
            A[i] = new int[n];
    


    
    
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++)
       {
          A[i][j]=0;
       }
   }
   //adding 5 edges
   A[0][4] = A[4][0] = 1;
   A[6][8] = A[8][6] =1;
   A[0][2] = A[2][0] =1;
   A[2][6] = A[6][2]= 1;
   A[1][9] = A[9][1] = 1;
   
   
   Graph g;
   
   //Setting the input
   g.setInput(A, 10);
   
   //This should output 5
   cout<<endl<<g.connectedComponents()<<endl;
   
    
  
    return 0;
}
