// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// Sol1 - O(N*(sum/2)) time and space
class Solution{
public:
    int equalPartition(int N, int arr[]) {
        int sum = accumulate(arr, arr+N, 0);
        
        // since ODD sum cannot be divided into two partitions
        if (sum % 2 == 1)
            return 0;
        
        // problem boils down to finding a subset of sum "sum/2"
        
        int mid = sum/2;
        
        vector<vector<bool> > dp(N, vector<bool>(mid + 1, 0));
        
        for (int i = 0; i < N; i++) {
            for (int j = 1; j <= mid; j++) {
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
        
        return dp[N-1][mid];
    }
};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
