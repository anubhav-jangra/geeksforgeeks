// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// Sol2 (using BFS) O(n2) time, O(n^2) space
class Solution {
    int row, col;
    vector<int> dx {0, 0, 1, -1};
    vector<int> dy {1, -1, 0, 0};
    bool isValid(int x, int y) {
        return (x >= 0 && x < row) and (y >= 0 and y < col);
    }
public:
    bool is_Possible(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        queue<pair<int, int>> q;
        
        int src_i, src_j;
        // traverse to find the source
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (grid[i][j] == 1) {
                    src_i = i; src_j = j;
                    break;
                }
        
        q.push(make_pair(src_i, src_j));
        visited[src_i][src_j] = true; // not needed, but just to be sure
        
        int x, y;
        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                if (isValid(x + dx[i], y + dy[i])) {
                    if (grid[ x + dx[i] ][ y + dy[i] ] == 2) return true;
                    
                    if (grid[ x + dx[i] ][ y + dy[i] ] == 3 && !visited[ x + dx[i] ][ y + dy[i] ]) {
                        visited[ x + dx[i] ][ y + dy[i] ] = true;
                        q.push(make_pair(x + dx[i], y + dy[i]));
                    }
                }
            }
        }
        
        return false;
    }
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends
