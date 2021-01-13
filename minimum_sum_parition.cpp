// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
public:
	int minDiffernce(int arr[], int n) {
	    int sum = accumulate(arr, arr+n, 0);
	    
	    vector<vector<bool>> dp(n, vector<bool>(sum, false));
	    
	    for (int i = 0; i < n; i++) {
	        for (int j = 1; j <= sum; j++) {
	            if (j == arr[i]) {
	                dp[i][j] = true;
	                continue;
	            }
	            if (i > 0) {
	                if (dp[i-1][j]) {
	                    dp[i][j] = true;
	                    continue;
	                }
	                if (j - arr[i] >= 0 && dp[i-1][j-arr[i]]) {
	                    dp[i][j] = true;
	                    continue;
	                }
	            }
	        }
	    }
	    
	    int min_diff = INT_MAX;
	    
	    for (int j = 1; j <= sum; j++)
	        if (dp[n-1][j]) {
	            // cout << "j: " << j << " val: " << abs(sum - 2*j) << endl;
	            min_diff = min(min_diff, abs(sum - 2*j));
	        }
	    
	    return min_diff;
	}
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDiffernce(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
