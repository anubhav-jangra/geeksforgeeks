#include <bits/stdc++.h>
using namespace std;

class Solution {
    int row, col;
    vector<int> dx {0, 1, 0, -1};
    vector<int> dy {1, 0, -1, 0};
    vector<vector<int>> matrix;
    bool isValid(int i, int j) {
        return (i >= 0 && i < row) and (j >= 0 && j < col);
    }
public:
    Solution(vector<vector<int>> &matrix_in) {
        row = matrix_in.size();
        col = matrix_in[0].size();
        matrix = matrix_in;
    }
    int minPath (int tgt_x, int tgt_y) {
        if (matrix[0][0] == 0) return -1; // handle the edge case that the start point is invalid!
        
        if (tgt_x == 0 && tgt_y == 0) return 0; // handle the edge case that the destination is the source (which is valid, i.e. 1)
        
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        queue<pair<int, pair<int, int>>> q;
        
        q.push(make_pair(0, make_pair(0, 0)));
        visited[0][0] = true;
        
        int x, y, dep;
        
        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second.first;
            dep = q.front().second.second;
            q.pop();
            
            // check if the desired node has been reached
            
            for (int i = 0; i < 4; i++) {
                if (isValid(x + dx[i], y + dy[i]) && matrix[ x + dx[i] ][ y + dy[i] ] == 1 && !visited[ x + dx[i] ][ y + dy[i] ]) {
                    if (x + dx[i] == tgt_x && y + dy[i] == tgt_y) return dep + 1;
                    visited[ x + dx[i] ][ y + dy[i] ] = true;
                    q.push(make_pair(x + dx[i], make_pair(y + dy[i], dep + 1)));
                }
            }
        }
        
        return -1;
    }
};

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int row, col;
	    cin >> row >> col;
	    vector<vector<int>> matrix (row, vector<int>(col, 0));
	    for (int i = 0; i < row; i++)
	        for (int j = 0; j < col; j++) 
	            cin >> matrix[i][j];
	    
	    Solution obj(matrix);
	    
	    int tgt_x, tgt_y;
	    cin >> tgt_x >> tgt_y;
	    
	    cout << obj.minPath(tgt_x, tgt_y) << endl;
	}
	return 0;
}
