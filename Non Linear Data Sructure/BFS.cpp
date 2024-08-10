#include<iostream>
#include<bits/stdc++.h>
#include<list>
using namespace std;
class Graph 
{
    int numvertices;
    list<int>* adjlist;
    bool* visited;
    public :
    Graph(int vertices);
    void addedge(int src,int dest);
    void BFS(int startvertex);
};
Graph ::Graph(int vertices)
{
    numvertices=vertices;
    adjlist=new list<int>[vertices];
}
void Graph::addedge(int src,int dest)
{
    adjlist[src].push_back(dest);
    adjlist[dest].push_back(src);
}
void Graph::BFS(int startvertex)
{
    visited=new bool[numvertices];
    for(int i=0;i<numvertices;i++)
    {
        visited[i]=false;
    }
    list<int>queue;
    visited[startvertex]=true;
    queue.push_back(startvertex);
    list<int>::iterator i;
    while(!queue.empty())
    {
        int currentvertex=queue.front();
        cout<<"Visited "<<currentvertex<<" ";
        queue.pop_front();
        for(i=adjlist[currentvertex].begin();i!=adjlist[currentvertex].end();++i)
        {
            int adjvertex=*i;
            if(!visited[adjvertex])
            {
                visited[adjvertex]=true;
                queue.push_back(adjvertex);
            }
        }
    }
}
int main()
{
    Graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.addedge(3,3);
    g.BFS(2);
}