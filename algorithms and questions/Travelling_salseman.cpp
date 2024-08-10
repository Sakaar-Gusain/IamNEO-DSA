/*
The Traveling Salesman Problem (TSP) involves finding the shortest possible route that visits each 
vertex exactly once and returns to the starting vertex in a complete graph with weighted edges.
Input 1 :
3
0 1 2
1 0 3
2 3 0

Output 1 :
Minimum Cost: 6

Input 2 :
5
0 2 3 4 5
2 0 6 7 8
3 6 0 9 10
4 7 9 0 11
5 8 10 11 0

Output 2 :
Minimum Cost: 30
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF=INT_MAX;

int tsp(int pos, int mask, vector<vector<int>>& dist, vector<vector<int>>&dp, int n){
    if(mask==(1<<n)-1){
        return dist[pos][0];
    }
    
    if(dp[pos][mask] != -1){
        return dp[pos][mask];
    }
    
    int result=INF;
    
    for(int city=0;city<n;++city){
        if((mask&(1<<city))==0){
            int newRes=dist[pos][city]+tsp(city,mask|(1<<city), dist, dp, n);
            result=min(result, newRes);
        }
    }
    dp[pos][mask]=result;
    return result;
}

int main(){
    int V;
    cin>>V;
    
    vector<vector<int>> dist(V,vector<int>(V));
    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j){
            cin>>dist[i][j];
        }
    }
    
    vector<vector<int>> dp(V,vector<int>(1<<V, -1));
    int r=tsp(0,1, dist, dp, V);
    cout<<"Minimum Cost: "<<r<<endl;
    
    return 0;
}