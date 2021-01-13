#include <bits/stdc++.h>
using namespace std;

// Failed Sol1 - O(n^2) solition, TLE for given problem (works fine though ;)
/*
int recurse(string s, int l, int r, vector<vector<int>> dp) {
    if (l >= r) return 0;
    if (dp[l][r] != INT_MAX) return dp[l][r];
    
    if (s[l] == s[r]) 
        dp[l][r] = recurse(s, l+1, r-1, dp);
    
    dp[l][r] = min(dp[l][r], 1 + recurse(s, l+1, r, dp));
    dp[l][r] = min(dp[l][r], 1 + recurse(s, l, r-1, dp));
    
    return dp[l][r];
}

int charsToPalindrome(string s) {
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), INT_MAX));
    
    return recurse(s, 0, s.length() - 1, dp);
}
*/

// Failed Sol2 - A small tweak on the Failed Sol1, still TLE
/*
int recurse(string s, int l, int r, vector<vector<int>> dp) {
    if (l >= r) return 0;
    if (dp[l][r] != INT_MAX) return dp[l][r];
    
    if (s[l] == s[r]) {
        dp[l][r] = recurse(s, l+1, r-1, dp);
        return dp[l][r];
    }
    
    dp[l][r] = min(dp[l][r], 1 + recurse(s, l+1, r, dp));
    dp[l][r] = min(dp[l][r], 1 + recurse(s, l, r-1, dp));
    
    return dp[l][r];
}

int charsToPalindrome(string s) {
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), INT_MAX));
    
    return recurse(s, 0, s.length() - 1, dp);
}
*/

// Failed Sol3: after peeking into the discussion; O(n^2) solition
// Top Down approach is not working out !!
/*
int recurse(string s, int l, int r, vector<vector<int>> dp) {
    if (l == r) return 1;
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    
    if (s[l] == s[r]) {
        dp[l][r] = 2 + recurse(s, l+1, r-1, dp);
        // return dp[l][r];
    }
    
    dp[l][r] = max(dp[l][r], recurse(s, l+1, r, dp));
    dp[l][r] = max(dp[l][r], recurse(s, l, r-1, dp));
    
    return dp[l][r];
}

int longestPalindromeSubsequence(string s) {
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
    
    return recurse(s, 0, s.length() - 1, dp);
}

int charsToPalindrome(string s) {
    int k = longestPalindromeSubsequence(s);
    // cout << "longest palindromic subsequence is: " << k << endl;
    return s.length() - k;
}
*/

int longestPalindromeSubsequence(string s) {
    int n = s.length();
    string t = s;
    reverse(t.begin(), t.end());
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    
    return dp[n][n];
}

int charsToPalindrome(string s) {
    int k = longestPalindromeSubsequence(s);
    // cout << "longest palindromic subsequence is: " << k << endl;
    return s.length() - k;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    string s;
	    cin >> s;
	    cout << charsToPalindrome(s) << endl;
	}
	return 0;
}
