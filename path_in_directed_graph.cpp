/*
In this problem we will check if there exist a path between given two nodes
the given graph will be a directed graph

input 1:
A = 5
 B = [  [1, 2] 
        [4, 1] 
        [2, 4] 
        [3, 4] 
        [5, 2] 
        [1, 3] ]
input 2:
 A = 5
 B = [  [1, 2]
        [2, 3] 
        [3, 4] 
        [4, 5] ]

----------------------------------------------------------------------
output 1:
 0 (print zero if there exist no path between 1 and A)

 output 2:
 1 (print 1 if there exist a path between 1 and A)

 I am using dfs graph traversal 
 I will start traversing from node 1 and if I find node A in the path I will return true otherwise false

*/


#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
void dfs( int start, vector<int> adj[], bool *vis,int A)
{
    vis[start]=true;
    if(start==A)
    {
        vis[A]=true;
        return;
    }
    for(int i=0;i<adj[start].size();i++)
    {
        if(vis[adj[start][i]]==false)
        {
            dfs(adj[start][i],adj,vis,A);
        }
    }
    return;
}

int main()
{
    int A = 5; // no of nodes starting with 1 ,2, 3 ...A
    vector<vector<int> > B{{1,2},{4,1},{2,4},{3,4},{5,2},{1,3}}; // edges of graph directed edges
    vector<int> adj[A+1];
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
    }
    bool vis[A+1];
    memset(vis,false,sizeof(vis));
    dfs(1,adj,vis,A);
    if(vis[A])
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    return 0;
}