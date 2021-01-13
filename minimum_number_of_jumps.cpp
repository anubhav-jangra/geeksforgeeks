// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Sol1 - O(n) time, O(1) space (after looking at the editorials)
int minJumps(int arr[], int n) {
    if (arr[0] == 0)
        return -1;
    int max_reach = arr[0], steps = arr[0], jumps = 1;
    for (int i = 1; i < n-1; i++) {
        max_reach = max(max_reach, i + arr[i]);
        steps--;
        
        if (steps == 0) {
            jumps++;
            if (i >= max_reach)
                return -1;
            
            steps = max_reach - i;
        }
    }
    
    return jumps;
}

// Failed Sol2 (Kinda O(n^2)) using brute force
/*
int minJumps(int arr[], int n) {
    vector<int> dp(n, INT_MAX);
    
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && dp[i] == INT_MAX)
            return -1;
        for (int j = min(i + arr[i], n-1); j > i; j--)
            dp[j] = min(dp[j], 1 + dp[i]);
    }
    
    // for (int i = 0; i < n; i++)
    //     cout << dp[i] << " ";
    // cout << " || ";
    return dp[n-1];
}
*/
// Function to return minimum number of jumps to end of array
// Failed Sol1 (kinda useless stuff)
/*
int minJumps(int arr[], int n) {
    
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        if (arr[i] == 0)
            return -1;
        cout << i << " ";
        i += arr[i] - 1;
        ans++;
    }
    
    return ans;
}
*/


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
