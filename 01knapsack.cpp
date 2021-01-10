// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Returns the maximum value that  
// can be put in a knapsack of capacity W 


int knapSack(int W, int wt[], int val[], int n) { 
   vector<vector<int> > dp(n, vector<int>(W+1, 0));
   
   for (int j = wt[0]; j <= W; j++)
       dp[0][j] = val[0];
   
   for (int i = 1; i < n; i++) {
       for (int j = 0; j <= W; j++) {
           if (i > 0)
               dp[i][j] = dp[i-1][j];
           if(j - wt[i] >= 0 && i > 0)
               dp[i][j] = max(dp[i][j], val[i] + dp[i-1][j - wt[i]]);
       }
   }
   
//   for (int i = 0; i < n; i++) {
//       for (int j = 0; j <= W; j++) {
//             cout << dp[i][j] << " ";
//       }
//       cout << endl;
//   }
   return dp[n-1][W];
}

// Failed sol1
/*
int knapSack(int W, int wt[], int val[], int n) { 
   vector<vector<int> > dp(n, vector<int>(W+1, 0));
   
   vector<vector<bool> > used(n, vector<bool>(W+1, false));
   
   for (int i = 0; i < n; i++) {
       for (int j = 0; j <= W; j++) {
           if (i > 0)
               dp[i][j] = dp[i-1][j];
           if (j - wt[i] >= 0) {
               if(!used[i][j - wt[i]])
                   dp[i][j] = max(dp[i][j], val[i] + dp[i][j - wt[i]]);
                used[i][j] = true;
           }
           if (j > 0) {
               dp[i][j] = max(dp[i][j], dp[i][j-1]);
           }
       }
   }

//   for (int i = 0; i < n; i++) {
//       for (int j = 0; j <= W; j++) {
//             cout << dp[i][j] << " ";
//       }
//       cout << endl;
//   }
   return dp[n-1][W];
}
*/




// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
