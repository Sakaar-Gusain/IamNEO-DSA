#include<bits/stdc++.h>
using namespace std;
#define V 4
#define INF 99999
void printSolution(int dist[][V]);
 
void floydWarshall(int dist[][V])
{
    int i,j,k;
    /* Adding all the vertices one by one to the set of intermediate vertices.
    Before start of an iteration, we have shortest distances between all the pairs of vertices such that the shortest distances consider only the 
    vertices set{0,1,2 ---- k-1} as intermediate vertices.
    After the end of the iteration vertex no. K is added to the set of intermediate vertices and the set becomes { 0,1,2------k)
    */
    for(k=0;k<V;k++)
    {
    //picking all vertices source one by one
    for(i=0;i<V;i++)
    {
    //pick all vertices as destination for the picked above source
    for(j=0;j<V;j++)
    {
        //If vertex K is on the shortest path from i to j , then update the value of dist[i][j]
        if(dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
        dist[i][j] = dist[i][k] + dist[k][j];
    }
    }
    }
    printSolution(dist);
}
void printSolution(int dist[][V])
{
    cout<<"Matrix shows the shortest distance between every pair of vertices\n";
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(dist[i][j] == INF)
            cout<<"INF";
            else
            cout<<dist[i][j]<<"  ";
        }
        cout<<endl;
    }
}
int main()
{
    int graph[V][V] = {{ 0, 5, INF, 10}, {INF, 0, 3, INF}, {INF, INF, 0, 1},{INF,INF,INF,0}};
    floydWarshall(graph);
}