// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 
long long countWays(int);
 
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		
		//calling function countWays()
		cout << countWays(n) << endl;
	}
    
    return 0;
    
}
// } Driver Code Ends


// O(n) time, O(1) space solution
/*
long long countWays(int n){
    
   if (n == 1) return 1;
   if (n == 2) return 2;
   if (n == 3) return 4;
   
   long long int val1 = 1, val2 = 2, val3 = 4, temp;
    
    for (int i = 4; i <= n; i++) {
        temp = val3;
        val3 = (((val3 + val2) % (1000000007)) + val1) % (1000000007);
        val1 = val2;
        val2 = temp;
    }
    
    return val3;
}
*/

// O(n) time, O(n) space solution

int max_val = 3;
vector<long long int> dp(10e5+1, -1);

long long countWays(int n){
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    long long int ans = 0;
    
    if (n <= max_val)
        return dp[n] % (1000000007);
    
    for (int i = max_val+1; i <= n; i++) {
        dp[i] = dp[i-1];
        dp[i] = (dp[i] + dp[i-2])  % (1000000007);
        dp[i] = (dp[i] + dp[i-3])  % (1000000007);
    }
    
    max_val = n;
    return dp[n];
}
