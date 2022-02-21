#include<iostream>
#include<bits/stdc++.h>
#include<map>


#include "Graph.h"

using namespace std;
     void Graph::setInput(int** A, int m)
     {
         
        for(int i=0;i<m;i++)
        {
            for(int j= 0;j<m;j++){
                
                if(i==j && A[i][j] == 1){cout<<"Input graph has self loops, exiting"<<endl;}
                if(A[i][j] !=A[j][i]){cout<<"Input matrix is not a valid adjacency matrix, exiting"<<endl;}
                 if(A[i][j]<0 || A[i][j] >1){cout<<"Input matrix is not a valid adjacency matrix, exiting"<<endl;}
            }
                
        }
        n = m;
        
        //allocating the memory for the private variable
        M = new int*[n];
         for(int i = 0; i < n; ++i)
            M[i] = new int[n];
        
        //Setting the adjacency matrix    
        for(int i=0;i<n;i++)
        {
            for(int j= 0;j<n;j++)
                M[i][j] = A[i][j];
        }
     }
     
    
    void Graph::dfs(int u,bool* visited){
 
    } 
     
    int Graph::connectedComponents(){
        
    
   }
    
    Graph::~Graph(){
        for(int i = 0; i < n; ++i)
            delete M[i];
    }
    
    