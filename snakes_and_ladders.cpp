// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++
// Sol2 (using bfs 
/*
class Solution{
    int shortestPath (vector<int> &grid, int idx) {
        vector<int> dp(31, INT_MAX);
        dp[1] = 0;
        
        queue<int> q;
        q.push(1);
        
        while (!q.empty()) {
            int i = q.front();
            // cout << "i: " << i << endl;
            q.pop();
            
            for (int d = 1; d < 7 && i + d <= 30; d++) {
                if (grid[i + d] != 0 && dp[ grid[i + d] ] == INT_MAX) { // ladder or snake
                    dp[ grid[i + d] ] = min(dp[ grid[i + d] ], dp[i] + 1);
                    q.push(grid[i + d]);
                } else { // nothing
                    if (dp[i + d] == INT_MAX) {
                        dp[i + d] = min(dp[i + d], dp[i] + 1);
                        q.push(i + d);
                    }
                }
            }
        }
        
        return dp[30];
    }
public:
    int minThrow(int N, int arr[]){
        
        vector<int> grid(31, 0);
        
        for (int i = 0; i < 2 * N; i += 2)
            grid[arr[i]] = arr[i+1];
        
        return shortestPath(grid, 1);
    }
};
*/

// Sol1
class Solution{
    int shortestPath (vector<int> &grid, int idx) {
        vector<int> dp(31, INT_MAX);
        dp[1] = 0;
        
        for (int i = 1; i < 30; i++) {
            if (dp[i] == INT_MAX) continue;
            
            for (int d = 1; d < 7 && i + d <= 30; d++) {
                
                if (grid[i + d] > i + d) { // ladder
                    dp[ grid[i + d] ] = min(dp[ grid[i + d] ], dp[i] + 1);
                } else if (grid[i + d] < i + d && dp[grid[i + d]] > dp[i] + 1) { // update i if snake outperforms general behaviour
                    dp[grid[i + d]] = dp[i] + 1;
                    i = grid[i + d];
                    break;
                } // else { // nothing
                dp[i + d] = min(dp[i + d], dp[i] + 1);
                // }
                
            }
        }
        
        return dp[30];
    }
public:
    int minThrow(int N, int arr[]){
        
        vector<int> grid(31, 0);
        
        for (int i = 0; i < 2 * N; i += 2)
            grid[arr[i]] = arr[i+1];
            
        return shortestPath(grid, 1);
    }
};

// Was trying to solve the problem in a 2d fashion, then it stricked to me that we can make it a 1d problem ;)
/*
class Solution{
    int shortestPath () {
    }
public:
    int minThrow(int N, int arr[]){
        
        vector<vector<int>> grid(5, vector<int>(6, 0));
        
        int counter = 2;
        for (int i = 4; i >= 0; i -= 2) {
            for (int j = 0; j < 6; j++) {
                grid[i][j] = counter++;
            }
            counter += 6;
        }
        
        counter = 8;
        for (int i = 3; i >= 0; i -= 2) {
            for (int j = 5; j >= 0; j--) {
                grid[i][j] = counter++;
            }
            counter += 6;
        }
        
        for (int i = 0; i < 2 * N; i += 2) {
            if ( (((arr[i] - 1) / 6) % 2) == 0) // increasing
                grid[ 4 - ((arr[i] - 1) / 6) ][ (arr[i] - 1) % 6 ] = arr[i+1];
            else // decreasing
                grid[ 4 - ((arr[i] - 1) / 6) ][ 5 - ((arr[i] - 1) % 6) ] = arr[i+1];
        }
        
        return shortestPath(grid);
    }
};
*/

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
