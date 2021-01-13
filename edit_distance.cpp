// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
private:
    vector<vector<int>> dp;
    int recurse(string s, string t, int x, int y) {
        if (x < 0 || y < 0) return max(x, y) + 1;
        if (dp[x][y] != -1) return dp[x][y];
        
        if (s[x] == t[y]) dp[x][y] = recurse(s, t, x-1, y-1);
        else {
            dp[x][y] = min(1 + recurse(s, t, x-1, y), 1 + recurse(s, t, x, y-1)); // remove the first element and second elemnet resp.
            dp[x][y] = min(1 + recurse(s, t, x-1, y-1), dp[x][y]); // replace one with another
        }
        return dp[x][y];
    }
public:
	int editDistance(string s, string t) {
	   // if (t.length() > s.length())
	   //     swap(s, t);
	        
	    dp.resize(s.length(), vector<int>(t.length(), -1));
	    for (int i = 0; i < dp.size(); i++) 
	        for (int j = 0; j < dp[0].size(); j++) 
	            dp[i][j] = -1;
	    int ans = recurse(s, t, s.length()-1, t.length()-1);
	    
	   // for (int i = 0; i < dp.size(); i++) {
	   //     for (int j = 0; j < dp[0].size(); j++) 
	   //         cout << dp[i][j] << " ";
	   //     cout << endl;
	   // }
	   // cout << endl;
	    
	    return ans;
	}
};


// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	int ans = ob.editDistance(s, t);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends
