#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

void dfs(int start, vector<int> adj[],bool *vis)
{
	vis[start]=true;
	cout<<start<<" ";
	for(int i=0;i<adj[start].size();i++)
	{
		if(vis[adj[start][i]]==false)
		{
			dfs(adj[start][i],adj,vis);
		}
	}
	return;
}
int main()
{
	int n; //no of nodes 
	int e; //no of edeges
	cout<<"please enter number of nodes"<<endl;
	cin>>n;
	cout<<"please enter number on edges "<<endl;
	cin>>e;
    vector<int> adj[n];
    bool vis[n];
    memset(vis,false,sizeof(vis));
    cout<<"please enter the edges info"<<endl;
    for(int i=0;i<e;i++)
    {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
	}
	dfs(1,adj,vis);
	cout<<endl;
}