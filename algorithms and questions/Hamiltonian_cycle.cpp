/*
Input 1 :
4
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0

Output 1 :
0 1 2 3 0


Input 2 :
3
0 1 0
1 0 1
0 1 0

Output 2 :
Solution does not exist
*/
#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int v,vector<vector<int>>& graph, vector<int>& path, int pos){
    if(graph[path[pos-1]][v]==0)
        return false;
    
    for(int i=0;i<pos;i++){
        if(path[i]==v)
            return false;
    }
    return true;
}


bool HamCycleU(vector<vector<int>>& graph, vector<int>& path, int pos, int V){
    if(pos==V){
        if(graph[path[pos-1]][path[0]]==1)
            return true;
        else
            return false;
    }
    
    for (int v=1;v<V;v++){
        if(isSafe(v, graph,path, pos)){
            path[pos]=v;
            
            if(HamCycleU(graph, path, pos+1, V)==true)
                return true;
            path[pos] =-1;
        }
    }
    return false;
}

void hamCycle(vector<vector<int>>& graph, int V){
    vector<int> path(V,-1);
    
    path[0]=0;
    if(!HamCycleU(graph, path,1,V)){
        cout<<"Solution does not exist"<<endl;
        return ;
    }
    
    for(int i=0;i<V;i++)
        cout<<path[i]<<" ";
    cout<<path[0]<<endl;
}

int main(){
    int V;
    cin>>V;
    
    vector<vector<int>> graph(V,vector<int>(V));
    
    for(int i=0;i<V;++i)
        for(int j=0;j<V;++j)
            cin>>graph[i][j];
    
    hamCycle(graph, V);
    return 0;
}