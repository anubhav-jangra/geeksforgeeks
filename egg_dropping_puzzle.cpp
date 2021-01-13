// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to get minimum number of trials needed in worst 
  case with n eggs and k floors */
int eggDrop(int n, int k) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    
    // trivial cases
    for (int j = 0; j <= k; j++)
        dp[1][j] = j;

    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1; dp[i][2] = 2;
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 3; j <= k; j++) {
            
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++)
                dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][x-1], dp[i][j-x]) );
            
        }
    }
    
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= k; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    return dp[n][k];
}

// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;

        //calling function eggDrop()
        cout<<eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
