#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
void bfs(int start,vector<int> adj[],bool *vis,int n)
{
	queue<int> q; // if we visit a node we will push it to the queue
	q.push(start);
	vis[start] = true;
	while(q.size()>0)
	{
		int curr = q.front(); // take the front element from the queue and explore it 
		q.pop();
		cout<<curr<<" ";
		for(int i=0;i<adj[curr].size();i++)
		{
			if(vis[adj[curr][i]] == false) // if the node is not visited push it to the queue
			{
				q.push(adj[curr][i]);
				vis[adj[curr][i]] = true; // when node is visited make the visited array true for that value
			}
		}
		
	}
}

int main()
{
	int n; //no of nodes
    int e; //no of edges
	cout<<"please enter no of nodes"<<endl;
	cin>>n;
	cout<<"please enter no of edges"<<endl;
	cin>>e;
	vector<int> adj[n]; // adj vector to store graph in list
	bool vis[n];   //boolean array to track if the node is visited or not 
    
	memset(vis,false,sizeof(vis));   //initialize the visited array with all false value
	cout<<"please enter edges info"<<endl;
	for(int i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		
	}
	bfs(0,adj,vis,n);
	return 0;
}