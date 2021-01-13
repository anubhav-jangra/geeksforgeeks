// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        
        //calling function maximizeTheCuts()
        cout<<maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}// } Driver Code Ends


int recurse(int n, int x, int y, int z, vector<int> &dp) {
    if (n == 0) return 0;
    else if (n < 0) return INT_MIN;
    if (dp[n] != -1) return dp[n];
    
    dp[n] = max(1+recurse(n-x, x, y, z, dp), 1+recurse(n-y, x, y, z, dp));
    dp[n] = max(dp[n], 1+recurse(n-z, x, y, z, dp));
    return dp[n];
}

int maximizeTheCuts(int n, int x, int y, int z) {
    vector<int> dp(n+1, -1);
    int ans = recurse(n, x, y, z, dp);
    if (ans < 0) return 0;
    return ans;
}
