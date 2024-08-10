//26-06-2024  Adjacency list representation of undirected graph
#include<bits/stdc++.h> 
using namespace std; 
vector<vector<int>> createAdjacencyList(vector<vector<int> >& edges, int numvertices) { 
    vector<vector<int>>adjList(numvertices); 
    for(int i=0; i<edges.size(); i++) { 
        int u = edges[i][0]; int v = edges[i][1]; 
        adjList[u].push_back(v); adjList[v].push_back(u); 
    } 
    return adjList; 
} 
int main() { 
    int numvertices = 4; 
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}, {3, 1}}; 
    vector<vector<int>> adjList = createAdjacencyList(edges, numvertices); 
    for(int i=0; i<numvertices;++i) { 
        cout<< i << " ->"; 
        for(int j=0; j<adjList[i].size();++j) { 
            cout<<adjList[i][j]<<" "; 
        } 
        cout<<endl; 
    } 
}