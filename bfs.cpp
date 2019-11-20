#include <bits/stdc++.h>
using namespace std;

class Graph
{
    private:
    	int V;
    	vector<int> *adj;
    	bool *visited;
    public:
    	Graph(int v)
        {
    		V = v;
    		isDir = false;
    		adj = new vector<int>[V];
    	}
    	void AddEdge(int u, int v)
        {
    		adj[u].push_back(v);

    		if(!isDir)
            	{
               	    adj[v].push_back(u);
            	}
    	}
    	void BFS(int s)
    	{
    		visited = new bool[V];

    		for(int i = 0 ; i < V ; i++)
            	{
    		    visited[i] = false;
    		}
    		
    		list<int> queue;
    		visited[s] = true;
    		queue.push_back(s);
    		
    		while(!queue.empty())
            	{
    	           int n = queue.front();
                   printf("%d\n", n);
                   queue.pop_front();
    			
    			vector<int>::iterator i;
    
    			for(i = adj[n].begin() ; i!= adj[n].end() ; i++)
                	{
    				if(visited[*i] == false)
                    		{
    				    visited[*i] = true;
    		                    queue.push_back(*i);
    				}
    			}
    		}
    	}
};
int main()
{
	int V , s ;
	scanf("%d%d", &V , &s);
	
	Graph g(V);
	
	int u , v ; 

	while(scanf("%d%d", &u , &v) != EOF)
    	{
	    g.AddEdge(u,v) ;
	}
	
	g.BFS(s) ;
	
	return 0 ;
}
