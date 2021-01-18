// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// Sol1
// Assumption that the graph is not empty
class Solution {
    vector<bool> visited;
    void dfsUtil(int V, vector<int> adj[], int idx, vector<int> &ans) {
        visited[idx] = true;
        for (int i = 0; i < adj[idx].size(); i++) {
            if (!visited[ adj[idx][i]]) {
                ans.push_back( adj[idx][i] );
                dfsUtil(V, adj, adj[idx][i], ans);
            }
        }
    }
public:
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    vector<int> ans;
	    ans.push_back(0);
	    visited = vector<bool> (V, false);
	    dfsUtil(V, adj, 0, ans);
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends