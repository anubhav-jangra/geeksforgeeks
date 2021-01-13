// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Sol1 - after peeking into the hints a bit
long long recurse(int arr[], int l, int r, vector<vector<long long>> &dp) {
    if (l > r) return 0;
    if (dp[l][r] != 0) return dp[l][r];
    
    // user picks left case
    dp[l][r] = arr[l] + min(recurse(arr, l + 2, r, dp), recurse(arr, l + 1, r - 1, dp));
    
    // user picks right case
    dp[l][r] = max(dp[l][r], arr[r] + min(recurse(arr, l, r - 2, dp), recurse(arr, l + 1, r - 1, dp)));
        
    return dp[l][r];
}

long long maximumAmount(int arr[], int n) {
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    
    int ans = recurse(arr, 0, n-1, dp);
    
    return ans;
}

// Failed Sol1 - assuming that the opponent does not behave optimally (not mentioned in problen anywhere!!)
/*
vector<vector<long long>> dp;

long long recurse(int arr[], int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != 0) return dp[l][r];
    
    // left left case
    dp[l][r] = arr[l] + recurse(arr, l + 2, r);
    
    // left right case
    dp[l][r] = max(dp[l][r], arr[l] + recurse(arr, l + 1, r - 1));
    
    // right left case
    dp[l][r] = max(dp[l][r], arr[r] + recurse(arr, l + 1, r - 1));
    
    // right right case
    dp[l][r] = max(dp[l][r], arr[r] + recurse(arr, l, r - 2));
    
    return dp[l][r];
}

long long maximumAmount(int arr[], int n) {
    dp.resize(n, vector<long long>(n, 0));
    
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;
    
    return recurse(arr, 0, n-1);
}
*/


// { Driver Code Starts.

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
