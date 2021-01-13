// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// Sol2 - O(nm) time, O(n) space
class Solution {
public:
    long long int count(int S[], int m, int n) {
       vector<long long int> dp(n+1, 0);
       
       for (int i = 0; i < m; i++) {
           for (int j = 1; j <= n; j++) {
               if (j == S[i]) dp[j] += 1; // made using this new coin
               // if (i > 0) dp[j] += dp[j]; // made using coins encountered so far // since it is the same array
               if (j - S[i] >= 0) dp[j] += dp[j - S[i]]; // ways to make j using one i and other ways to make j-S[i]
           }
       }
       
       return dp[n];
    }
};

// Sol1 - O(nm) time, O(nm) space
/*
class Solution {
public:
    long long int count(int S[], int m, int n) {
       vector<vector<long long int> > dp(m, vector<long long int>(n+1, 0));
       
       for (int i = 0; i < m; i++) {
           for (int j = 1; j <= n; j++) {
               if (j == S[i]) dp[i][j] += 1; // made using this new coin
               if (i > 0) dp[i][j] += dp[i-1][j]; // made using coins encountered so far
               if (j - S[i] >= 0) dp[i][j] += dp[i][j - S[i]]; // ways to make j using one i and other ways to make j-S[i]
           }
       }
       
       return dp[m-1][n];
    }
};
*/

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends
