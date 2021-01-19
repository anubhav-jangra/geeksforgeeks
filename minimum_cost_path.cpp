// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// sol1 (Caved in to the final solution :( )
struct Ele {
    int cost;
    int x;
    int y;
};

bool operator<(const Ele &a, const Ele &b) {
    if (a.cost == b.cost) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    }
    
    return a.cost < b.cost;
}

class Solution {
    int row, col; // same for this question
    vector<int> dx {0, 1, -1, 0}; // d, r, l, u
    vector<int> dy {1, 0, 0, -1};
    map<int, int> mp = {{0, 3}, {3, 0}, {1, 2}, {2, 1}};
    bool isValid(int x, int y) {
        return (x >= 0 && x < row) and (y >= 0 && y < col);
    }
public:
    int minimumCostPath(vector<vector<int>>& grid) {
        // handle edge case of the grid being of size 1x1
        if (grid.size() == 1) return grid[0][0];
        
        row = grid.size();
        col = grid[0].size();
        
        vector<vector<int>> costs (row, vector<int>(col, INT_MAX));
        
        set<Ele> q;
        
        q.insert({0, 0, 0});
        costs[0][0] = grid[0][0];
        
        int x, y, curr_val;
        while (!q.empty()) {
            x = (*q.begin()).x;
            y = (*q.begin()).y;
            q.erase(q.begin());
            
            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i], new_y = y + dy[i];
                if (isValid(new_x, new_y) && costs[new_x][new_y] > costs[x][y] + grid[new_x][new_y]) {
                    if (costs[new_x][new_y] != INT_MAX) // remove the existing entry
                        q.erase(q.find({costs[new_x][new_y], new_x, new_y}));
                    
                    costs[new_x][new_y] = costs[x][y] + grid[new_x][new_y];
                    q.insert({costs[new_x][new_y], new_x, new_y});
                }
            }
        }
        return costs[row-1][col-1];
    }
};

// Failed Sol3 (TLE) 
/*
class Solution {
    int row, col; // same for this question
    vector<int> dx {0, 1, -1, 0}; // d, r, l, u
    vector<int> dy {1, 0, 0, -1};
    map<int, int> mp = {{0, 3}, {3, 0}, {1, 2}, {2, 1}};
    bool isValid(int x, int y) {
        return (x >= 0 && x < row) and (y >= 0 && y < col);
    }
public:
    int minimumCostPath(vector<vector<int>>& grid) {
        // handle edge case of the grid being of size 1x1
        if (grid.size() == 1) return grid[0][0];
        
        row = grid.size();
        col = grid[0].size();
        
        vector<vector<int>> costs (row, vector<int>(col, INT_MAX));
        
        set<vector<int>> q; // vector containts: 1 - row, 2 - col, 0 - curr_score
        
        q.insert(vector<int>{grid[0][0], 0, 0});
        costs[0][0] = grid[0][0];
        
        int x, y, curr_val;
        while (!q.empty()) {
            x = (*q.begin())[1];
            y = (*q.begin())[2];
            curr_val = (*q.begin())[0];
            q.erase(*q.begin());
            
            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i], new_y = y + dy[i];
                if (isValid(new_x, new_y) && costs[new_x][new_y] > costs[x][y] + grid[new_x][new_y]) {
                    if (costs[new_x][new_y] != INT_MAX) // remove the existing entry
                        q.erase(q.find(vector<int>{costs[new_x][new_y], new_x, new_y}));
                    
                    costs[new_x][new_y] = min(costs[new_x][new_y], curr_val + grid[new_x][new_y]);
                    q.insert(vector<int>{curr_val + grid[new_x][new_y], new_x, new_y});
                }
            }
        }
        return costs[row-1][col-1];
    }
};
*/

// Failed Sol2 (TLE)
/*
class Solution {
    int row, col; // same for this question
    vector<int> dx {0, 1, -1, 0}; // d, r, l, u
    vector<int> dy {1, 0, 0, -1};
    map<int, int> mp = {{0, 3}, {3, 0}, {1, 2}, {2, 1}};
    bool isValid(int x, int y) {
        return (x >= 0 && x < row) and (y >= 0 && y < col);
    }
public:
    int minimumCostPath(vector<vector<int>>& grid) {
        // handle edge case of the grid being of size 1x1
        if (grid.size() == 1) return grid[0][0];
        
        row = grid.size();
        col = grid[0].size();
        
        vector<vector<int>> costs (row, vector<int>(col, INT_MAX));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q; // vector containts: 1 - row, 2 - col, 0 - curr_score
        
        vector<vector<bool>> visited (row, vector<bool>(col, false));
        
        q.push(vector<int>{grid[0][0], 0, 0});
        costs[0][0] = grid[0][0];
        
        int x, y, curr_val;
        while (!q.empty()) {
            x = q.top()[1];
            y = q.top()[2];
            curr_val = q.top()[0];
            q.pop();
            if (curr_val != costs[x][y]) {
                q.push(vector<int>{costs[x][y], x, y}); 
                continue;
            }
            visited[x][y] = true;
            
            for (int i = 0; i < 4; i++) {
                if (isValid(x + dx[i], y + dy[i]) && !visited[ x + dx[i] ][ y + dy[i] ]) {
                    costs[ x + dx[i] ][ y + dy[i] ] = min(costs[ x + dx[i] ][ y + dy[i] ], curr_val + grid[ x + dx[i] ][ y + dy[i] ]);
                    
                    q.push(vector<int>{curr_val + grid[ x + dx[i] ][ y + dy[i] ], x + dx[i], y + dy[i]});
                }
            }
        }
        return costs[row-1][col-1];
    }
};
*/

// A failed brute force solution!
/*
class Solution {
    int row, col; // same for this question
    vector<int> dx {0, 1, -1, 0}; // d, r, l, u
    vector<int> dy {1, 0, 0, -1};
    map<int, int> mp = {{0, 3}, {3, 0}, {1, 2}, {2, 1}};
    bool isValid(int x, int y) {
        return (x >= 0 && x < row) and (y >= 0 && y < col);
    }
public:
    int minimumCostPath(vector<vector<int>>& grid) {
        // handle edge case of the grid being of size 1x1
        if (grid.size() == 1) return grid[0][0];
        
        row = grid.size();
        col = grid[0].size();
        queue<vector<int>> q; // vector containts: 0 - row, 1 - col, 2 - curr_score, 3 - direction to avoid (opposite of one last taken)
        
        q.push(vector<int> {0, 0, grid[0][0], -1}); // nothing to avoid in the first case
        
        vector<vector<int>> costs (row, vector<int>(col, INT_MAX));
        
        int x, y, curr_val, avoid_d;
        while (!q.empty()) {
            cout << x << ", " << y << endl;
            x = q.front()[0];
            y = q.front()[1];
            curr_val = q.front()[2];
            avoid_d = q.front()[3];
            q.pop();
            
            costs[x][y] = min(costs[x][y], curr_val);
            if (x == row - 1 && y == col - 1) continue;
            
            for (int i = 0; i < 4; i++) {
                if (avoid_d != i && isValid(x + dx[i], y + dy[i])) { // otherwise a loop will be formed
                    q.push(vector<int> {x + dx[i], y + dy[i], curr_val + grid[ x + dx[i] ][ y + dy[i] ], mp[i]});
                }
            }
        }
        return costs[row-1][col-1];
    }
};
*/

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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
