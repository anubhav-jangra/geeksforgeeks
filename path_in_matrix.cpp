// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
    vector<vector<int>> dp;
    int recurse(vector<vector<int>> &Matrix, int i, int j) {
        if (i >= Matrix.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        if (j > 0) dp[i][j] = recurse(Matrix, i + 1, j - 1);
        if (j < Matrix.size() - 1) dp[i][j] = max(dp[i][j], recurse(Matrix, i + 1, j + 1));
        dp[i][j] = max(dp[i][j], recurse(Matrix, i + 1, j));
        dp[i][j] += Matrix[i][j];
        return dp[i][j];
    }
public:
    int maximumPath(int N, vector<vector<int>> &Matrix) {
        
        // edge case
        if (N == 1) return Matrix[0][0];
        
        dp.resize(N, vector<int>(N, -1));
        
        for (int j = 0; j < N; j++) {
            if (j > 0)
                dp[0][j] = recurse(Matrix, 1, j-1);
            if (j < N-1)
                dp[0][j] = max(dp[0][j], recurse(Matrix, 1, j+1));
            dp[0][j] = max(dp[0][j], recurse(Matrix, 1, j));
            
            dp[0][j] += Matrix[0][j];
        }
        
        int ans = INT_MIN;
        for (int j = 0; j < N; j++)
            if (dp[0][j] > ans)
                ans = dp[0][j];
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
