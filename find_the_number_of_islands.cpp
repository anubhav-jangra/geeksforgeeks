// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// Sol3 (styled Sol2) (peeked from full solution)
class Solution {
    int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int row, col;
    bool isValid(int x, int y) {
        return (x >= 0 && x < row) and (y >= 0 && y < col);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size(); col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        int ans = 0, x, y;
        queue<pair<int, int>> q;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ans++;
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                    
                    while (!q.empty()) {
                        x = q.front().first;
                        y = q.front().second;
                        q.pop();
                        
                        for (int p = 0; p < 8; p++) {
                            if (isValid(x + dx[p], y + dy[p]) && grid[ x + dx[p] ][ y + dy[p] ] == '1' && !visited[ x + dx[p] ][ y + dy[p] ]) {
                                q.push(make_pair(x + dx[p], y + dy[p]));
                                visited[ x + dx[p] ][ y + dy[p] ] = true;
                            }
                        }
                    }
                }
        
        return ans;
    }
};

// Sol2 (using BFS)
/*
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size(), col = grid[0].size();
        
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int, int>> q;
        int ans = 0, neigh;
        
        pair<int, int> temp;
        
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ans++;
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                    
                    while (!q.empty()) {
                        temp = q.front();
                        q.pop();
                        
                        // checking the horizontal and vertical directions
                        if (temp.first - 1 >= 0   && grid[temp.first - 1][temp.second] == '1' && !visited[temp.first - 1][temp.second]) {
                            q.push(make_pair(temp.first - 1, temp.second));
                            visited[temp.first - 1][temp.second] = true;
                        }
                        
                        if (temp.first + 1 < row  && grid[temp.first + 1][temp.second] == '1' && !visited[temp.first + 1][temp.second]) {
                            q.push(make_pair(temp.first + 1, temp.second));
                            visited[temp.first + 1][temp.second] = true;
                        }
                        
                        if (temp.second + 1 < col && grid[temp.first][temp.second + 1] == '1' && !visited[temp.first][temp.second + 1]) {
                            q.push(make_pair(temp.first, temp.second + 1));
                            visited[temp.first][temp.second + 1] = true;
                        }
                        
                        if (temp.second - 1 >= 0  && grid[temp.first][temp.second - 1] == '1' && !visited[temp.first][temp.second - 1]) {
                            q.push(make_pair(temp.first, temp.second - 1));
                            visited[temp.first][temp.second - 1] = true;
                        }
                        
                        // checking the four diagonal directions
                        if (temp.first - 1 >= 0  && temp.second - 1 >= 0  && grid[temp.first - 1][temp.second - 1] == '1' && !visited[temp.first - 1][temp.second - 1]) {
                            q.push(make_pair(temp.first - 1, temp.second - 1));
                            visited[temp.first - 1][temp.second - 1] = true;
                        }
                        
                        if (temp.first + 1 < row && temp.second - 1 >= 0  && grid[temp.first + 1][temp.second - 1] == '1' && !visited[temp.first + 1][temp.second - 1]) {
                            q.push(make_pair(temp.first + 1, temp.second - 1));
                            visited[temp.first + 1][temp.second - 1] = true;
                        }
                        
                        if (temp.first - 1 >= 0  && temp.second + 1 < col && grid[temp.first - 1][temp.second + 1] == '1' && !visited[temp.first - 1][temp.second + 1]) {
                            q.push(make_pair(temp.first - 1, temp.second + 1));
                            visited[temp.first - 1][temp.second + 1] = true;
                        }
                        
                        if (temp.first + 1 < row && temp.second + 1 < col && grid[temp.first + 1][temp.second + 1] == '1' && !visited[temp.first + 1][temp.second + 1]) {
                            q.push(make_pair(temp.first + 1, temp.second + 1));
                            visited[temp.first + 1][temp.second + 1] = true;
                        }
                    }
                }
        
        return ans;
    }
};
*/

// Sol1 (using DFS)
/*
class Solution {
    vector<vector<bool>> visited;
    int row, col;
    void utilFunc(vector<vector<char>>& grid, int i_, int j_) {
        
        visited[i_][j_] = true;
        
        if (i_ - 1 >= 0 && grid[i_ - 1][j_] == '1' && !visited[i_ - 1][j_]) utilFunc(grid, i_ - 1, j_);
            
        if (i_ + 1 < row && grid[i_ + 1][j_] == '1' && !visited[i_ + 1][j_]) utilFunc(grid, i_ + 1, j_);
        
        if (j_ - 1 >= 0 && grid[i_][j_ - 1] == '1' && !visited[i_][j_ - 1]) utilFunc(grid, i_, j_ - 1);
            
        if (j_ + 1 < col && grid[i_][j_ + 1] == '1' && !visited[i_][j_ + 1]) utilFunc(grid, i_, j_ + 1);
            
        if (i_ - 1 >= 0 && j_ - 1 >= 0 && grid[i_ - 1][j_ - 1] == '1' && !visited[i_ - 1][j_ - 1]) utilFunc(grid, i_ - 1, j_ - 1);
        
        if (i_ + 1 < row && j_ - 1 >= 0 && grid[i_ + 1][j_ - 1] == '1' && !visited[i_ + 1][j_ - 1]) utilFunc(grid, i_ + 1, j_ - 1);
        
        if (i_ - 1 >= 0 && j_ + 1 < col && grid[i_ - 1][j_ + 1] == '1' && !visited[i_ - 1][j_ + 1]) utilFunc(grid, i_ - 1, j_ + 1);
        
        if (i_ + 1 < row && j_ + 1 < col && grid[i_ + 1][j_ + 1] == '1' && !visited[i_ + 1][j_ + 1]) utilFunc(grid, i_ + 1, j_ + 1);
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        row = grid.size();
        col = grid[0].size();
        
        visited = vector<vector<bool>> (row, vector<bool>(col, false));
        int ans = 0;
        
        pair<int, int> temp;
        
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ans++;
                    utilFunc(grid, i, j);
                }
        return ans;
    }
};
*/

// Failed Sol2 (optimized Failed Sol1), TLE
/*
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size(), col = grid[0].size();
        
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int, int>> q;
        int ans = 0, neigh;
        
        pair<int, int> temp;
        
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ans++;
                    q.push(make_pair(i, j));
                    // cout << "pushing : " << i << ", " << j << endl;
        
                    while (!q.empty()) {
                        temp = q.front();
                        q.pop();
                        // cout << "popping : " << temp.first << ", " << temp.second << endl;
                        visited[temp.first][temp.second] = true;
                        
                        // checking the horizontal and vertical directions
                        if (temp.first - 1 >= 0) {
                            if (grid[temp.first - 1][temp.second] == '1' && !visited[temp.first - 1][temp.second])
                                q.push(make_pair(temp.first - 1, temp.second));
                                
                            if (temp.second - 1 >= 0)
                                if (grid[temp.first - 1][temp.second - 1] == '1' && !visited[temp.first - 1][temp.second - 1])
                                    q.push(make_pair(temp.first - 1, temp.second - 1));
                            
                            if (temp.second + 1 < col)
                                if (grid[temp.first - 1][temp.second + 1] == '1' && !visited[temp.first - 1][temp.second + 1])
                                    q.push(make_pair(temp.first - 1, temp.second + 1));
                        }
                        
                        if (temp.first + 1 < row) {
                            if (grid[temp.first + 1][temp.second] == '1' && !visited[temp.first + 1][temp.second])
                                q.push(make_pair(temp.first + 1, temp.second));
                                
                            if (temp.second - 1 >= 0)
                                if (grid[temp.first + 1][temp.second - 1] == '1' && !visited[temp.first + 1][temp.second - 1])
                                    q.push(make_pair(temp.first + 1, temp.second - 1));
                            
                            if (temp.second + 1 < col)
                                if (grid[temp.first + 1][temp.second + 1] == '1' && !visited[temp.first + 1][temp.second + 1])
                                    q.push(make_pair(temp.first + 1, temp.second + 1));
                        }
                        
                        if (temp.second - 1 >= 0)
                                if (grid[temp.first][temp.second - 1] == '1' && !visited[temp.first][temp.second - 1])
                                    q.push(make_pair(temp.first, temp.second - 1));
                        if (temp.second + 1 < col)
                                if (grid[temp.first][temp.second + 1] == '1' && !visited[temp.first][temp.second + 1])
                                    q.push(make_pair(temp.first, temp.second + 1));
                    }
                }
        
        return ans;
    }
};
*/
// Failed Sol1 (using BFS) : TLE
/*
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size(), col = grid[0].size();
        
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int, int>> q;
        int ans = 0, neigh;
        
        pair<int, int> temp;
        
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ans++;
                    q.push(make_pair(i, j));
        
                    while (!q.empty()) {
                        temp = q.front();
                        q.pop();
                        visited[temp.first][temp.second] = true;
                        
                        // checking the horizontal and vertical directions
                        if (temp.first - 1 >= 0   && grid[temp.first - 1][temp.second] == '1' && !visited[temp.first - 1][temp.second])
                            q.push(make_pair(temp.first - 1, temp.second));
                        
                        if (temp.first + 1 < row  && grid[temp.first + 1][temp.second] == '1' && !visited[temp.first + 1][temp.second])
                            q.push(make_pair(temp.first + 1, temp.second));
                        
                        if (temp.second + 1 < col && grid[temp.first][temp.second + 1] == '1' && !visited[temp.first][temp.second + 1])
                            q.push(make_pair(temp.first, temp.second + 1));
                        
                        if (temp.second - 1 >= 0  && grid[temp.first][temp.second - 1] == '1' && !visited[temp.first][temp.second - 1])
                            q.push(make_pair(temp.first, temp.second - 1));
                        
                        // checking the four diagonal directions
                        if (temp.first - 1 >= 0  && temp.second - 1 >= 0  && grid[temp.first - 1][temp.second - 1] == '1' && !visited[temp.first - 1][temp.second - 1])
                            q.push(make_pair(temp.first - 1, temp.second - 1));
                        
                        if (temp.first + 1 < row && temp.second - 1 >= 0  && grid[temp.first + 1][temp.second - 1] == '1' && !visited[temp.first + 1][temp.second - 1])
                            q.push(make_pair(temp.first + 1, temp.second - 1));
                        
                        if (temp.first - 1 >= 0  && temp.second + 1 < col && grid[temp.first - 1][temp.second + 1] == '1' && !visited[temp.first - 1][temp.second + 1])
                            q.push(make_pair(temp.first - 1, temp.second + 1));
                        
                        if (temp.first + 1 < row && temp.second + 1 < col && grid[temp.first + 1][temp.second + 1] == '1' && !visited[temp.first + 1][temp.second + 1])
                            q.push(make_pair(temp.first + 1, temp.second + 1));
                    }
                }
        
        return ans;
    }
};
*/


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends
