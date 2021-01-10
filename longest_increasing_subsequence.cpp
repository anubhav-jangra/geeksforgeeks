// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];

        //calling method longestSubsequence()
        cout << longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends


// return length of longest strictly increasing subsequence

// O(n2 solution)
int longestSubsequence(int n, int a[]) {
    vector<int> dp(n, -1);
    
    int prev;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

// Better implementation using lower_bound
/*
int longestSubsequence(int n, int a[]) {
   vector<int> dp(n, -1);
   
   int counter = 1, pos;
   dp[0] = a[0];
   for (int i = 1; i < n; i++) {
       pos = lower_bound(dp.begin(), dp.begin() + counter, a[i]) - dp.begin();
       dp[pos] = a[i];
       if (pos == counter)
            counter++;
   }
   return counter;
}
*/
/*
int longestSubsequence(int n, int a[]) {
   vector<int> dp(n, -1);
   
   int counter = 1, pos;
   dp[0] = a[0];
   for (int i = 1; i < n; i++) {
       pos = upper_bound(dp.begin(), dp.begin() + counter, a[i]) - dp.begin();
       if (pos > 0 && dp[pos-1] == a[i])
            pos--;
       dp[pos] = a[i];
       if (pos == counter)
            counter++;
   }
   return counter;
}
*/

