// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends




class Solution{
public:
    string longestCommonPrefix (string arr[], int N) {
        string ans = "";
        
        int min_len = INT_MAX, i, j;
        for (i = 0; i < N; i++)
            min_len = min(min_len, (int) arr[i].length());
        
        
        for (i = 0; i < min_len; i++) {
            for (j = 0; j < N; j++) {
                if (j != 0 && arr[j][i] != arr[j-1][i])
                    goto here;
            }
        }
        
        here:
        if (i == 0) return "-1";
        return arr[0].substr(0, i);
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends
