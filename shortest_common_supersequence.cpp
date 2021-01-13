// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(char* , char*, int, int );

int main()
{   
    
    int t;
    char X[10001], Y[10001];
    
    //taking total testcases
    cin >> t;
    while(t--){
    
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	cout << shortestCommonSupersequence(X, Y, strlen(X), strlen(Y))<< endl;
    }
	return 0;
}

// } Driver Code Ends


//User function template for C++

// X : 1st given string of size m
// Y : 2nd given string of size n

int recurse(char* X, char* Y, int m, int n, vector<vector<int>> &dp) {
    if (m < 0 || n < 0) return 1 + max(m, n);
    if (dp[m][n] != -1) return dp[m][n];
    
    if (X[m] == Y[n]) dp[m][n] = 1 + recurse(X, Y, m-1, n-1, dp);
    else dp[m][n] = min(1 + recurse(X, Y, m-1, n, dp), 1 + recurse(X, Y, m, n-1, dp));
    
    return dp[m][n];
}

int shortestCommonSupersequence(char* X, char* Y, int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    
    int ans = recurse(X, Y, m-1, n-1, dp);
    
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    return ans;
}
