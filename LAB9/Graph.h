#include<bits/stdc++.h>
#include<map>

class Graph{
    private:
     int n;
     int** M;
     
     public:
     
     void setInput(int **A, int m);
     
    int connectedComponents();
    
    void dfs(int x, bool* visited);
    
    ~Graph();
    
    
};