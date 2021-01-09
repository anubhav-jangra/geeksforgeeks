#include <bits/stdc++.h>
using namespace std;

// Sol2 using dynamic programming (a mixture of recursive and iterative approach xD)
class Solution {
    vector<vector<int>> dp;
    int recurse(string s1, string s2, int n, int m) {
        if (n < 0 || m < 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];
        if (s1[n] == s2[m])
            return 1 + recurse(s1, s2, n-1, m-1);
        else
            return 0;
    }
public:
    int longestSubstring(string s1, string s2, int n, int m) {
        if (m > n) {
            swap(s1, s2); swap(m, n);
        }
        
        // s1 > s2; n > m
        dp.resize(n, vector<int>(m, -1));
        
        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = recurse(s1, s2, i, j);
                // cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << endl;
                if (dp[i][j] > ans)
                    ans = dp[i][j];
            }
        }
        
        return ans;
    }
};

// Sol1 Brute force; O(n*m) time, O(1 space)
/*
class Solution {
    int recurse(string s1, string s2, int n, int m) {
        if (n < 0 || m < 0)
            return 0;
        if (s1[n] == s2[m])
            return 1 + recurse(s1, s2, n-1, m-1);
        else
            return 0;
    }
public:
    int longestSubstring(string s1, string s2, int n, int m) {
        if (m > n) {
            swap(s1, s2); swap(m, n);
        }
        
        // s1 > s2; n > m
        
        int ans = -1, temp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp = recurse(s1, s2, i, j);
                // cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << endl;
                if (temp > ans)
                    ans = temp;
            }
        }
        
        return ans;
    }
};
*/

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n, m;
	    cin >> n >> m;
	    string s1, s2;
	    cin >> s1 >> s2;
        Solution sol;
	    cout << sol.longestSubstring(s1, s2, n, m) << endl;
	}
	return 0;
}

