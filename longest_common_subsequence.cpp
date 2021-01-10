// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


// function to find longest common subsequence

vector<vector<int> > dp(101, vector<int>(101, -1));

int recurse (int l1, int l2, string s1, string s2) {
    if (l1 < 0 || l2 < 0) return 0;
    if (dp[l1][l2] != -1) return dp[l1][l2];
    
    if (s1[l1] == s2[l2])
        dp[l1][l2] = 1 + recurse(l1-1, l2-1, s1, s2);
    else
        dp[l1][l2] = max(recurse(l1, l2-1, s1, s2), recurse(l1-1, l2, s1, s2));
    
    return dp[l1][l2];
}

int lcs(int l1, int l2, string s1, string s2){
    
    // resetting the dp matrix
    for (int i = 0; i < l1; i++)
        for (int j = 0; j < l2; j++)
            dp[i][j] = -1;
    
    return recurse(l1-1, l2-1, s1, s2);
}

// Failed attempt 1
// a two pointer solution with constant space (does not work)
/*
int lcs(int l1, int l2, string s1, string s2){
    
    int p1 = 0, p2 = 0, ans = 0;
    
    int i; // for loops
    while (p1 < l1 && p2 < l2) {
        
        // looping over the second string
        for (i = p2; i < l2; i++) {
            if (s1[p1] == s2[i]) {
                cout << s1[p1];
                p2 = i+1;
                ans++;
                break;
            }
        }
        
        p1++;
    }
    
    cout << endl;
    return ans;
}
*/

