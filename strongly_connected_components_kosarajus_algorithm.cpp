// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    stack<int> stk;
    vector<bool> visited;
public:
	/*  Function to find the number of strongly connected components
    *   using Kosaraju's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */
    
    void dfsUtil (int V, vector<int> adj[], int idx) {
        visited[idx] = true;
        
        for (auto i : adj[idx]) if (!visited[i]) dfsUtil(V, adj, i);
        stk.push(idx);
    }
    
    void dfsUtil_2 (int V, vector<int> adj[], int idx) {
        visited[idx] = true;
        
        for (auto i : adj[idx]) if (!visited[i]) dfsUtil(V, adj, i);
    }
    
    int kosaraju(int V, vector<int> adj[]) {
        while (!stk.empty()) stk.pop();
        visited = vector<bool> (V, false);
        
        for (int i = 0; i < V; i++)
            if (!visited[i])
                dfsUtil (V, adj, i);
        
        // testing out topological sort program, cause the gfg practice was not accessible
        // while (!stk.empty()) {
        //     cout << stk.top() << " ";
        //     stk.pop();
        // }
        // cout << endl;
        
        // reversing the adjacency matrix
        vector<int> adj_t[V];
        for (int i = 0; i < V; i++)
            for (int j = 0; j < adj[i].size(); j++)
                adj_t[ adj[i][j] ].push_back(i);
        
        // reset visited array
        visited = vector<bool> (V, false);
        int ans = 0, temp;
        while (!stk.empty()) {
            temp = stk.top();
            stk.pop();
            if (!visited[temp]) {
                ans++;
                dfsUtil_2(V, adj_t, temp);
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
