// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// Sol2 (using BFS)
class Solution {
public:
	bool isCycle(int V, vector<int> adj[]) {
	   	vector<bool> visited(V, false);
	   	vector<int> parent(V, -1);
	   	
	   	queue<int> q;
	   	int temp;
	   	
	   	for (int i = 0; i < V; i++) {
	   	    if (visited[i]) continue;
	   	    q.push(i);
	   	    visited[i] = true;
	   	    
	   	    while (!q.empty()) {
	   	        temp = q.front();
	   	        q.pop();
	   	        
	   	        for (int j = 0; j < adj[temp].size(); j++) {
	   	            if (visited[ adj[temp][j] ]) {
	   	                if (adj[temp][j] != parent[temp])
	   	                    return true;
	   	                else
	   	                    continue;
	   	            }
	   	            q.push(adj[temp][j]);
	   	            visited[ adj[temp][j] ] = true;
	   	            parent[ adj[temp][j] ] = temp;
	   	        }
	   	    }
	   	}
	   	
	   	return false;
	}
};

// Sol1 O(V+E) time, O(V) space (using DFS)
/*
class Solution {
    vector<bool> visited;
    bool utilFunc(int V, vector<int>adj[], int idx, int parent) {
        visited[idx] = true;
        for (int i = 0; i < adj[idx].size(); i++) {
            if (visited[ adj[idx][i] ] && parent != adj[idx][i])
                return true;
            else if (!visited[ adj[idx][i] ] && utilFunc(V, adj, adj[idx][i], idx))
                return true;
        }
        return false;
    }
public:
	bool isCycle(int V, vector<int>adj[]){
	    if (V <= 0) return true;
	    
	    visited = vector<bool>(V, false);
	    for (int i = 0; i < V; i++)
	        if (!visited[i] && utilFunc(V, adj, i, -1))
	            return true;
	    return false;
	}
};
*/

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
