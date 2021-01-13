#include <bits/stdc++.h>
using namespace std;

// Wrote a code to find the length of max Palindrome by mistake xD
/*
int recurse(string s, int l, int r, vector<vector<int>> dp) {
    if (l > r) return 0;
    if (l == r) {
        dp[l][r] = 1;
        return 1;
    }
    if (dp[l][r] != -1) return dp[l][r];
    
    if (s[l] == s[r]) dp[l][r] = 2 + recurse(s, l + 1, r - 1, dp);
    dp[l][r] = max(dp[l][r], recurse(s, l + 1, r, dp));
    dp[l][r] = max(dp[l][r], recurse(s, l, r - 1, dp));
    
    return dp[l][r];
}

int longestPalindrome(string s) {
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
    
    int ans_size = recurse(s, 0, s.length()-1, dp);
    
    return ans_size;
}
*/

// Failed sol1 (quite a messed up implementation :/)
/*
pair<int, int> recurse(string s, int l, int r, vector<vector<pair<int, int>>> &dp) {
    // cout << l << ", " << r << endl;
    if (l > r) return make_pair(l, r);
    if (s[l-1] == s[r+1] && s[l] != s[r]) return make_pair(-1, -1);
    if (l == r) {
        dp[l][r] = make_pair(l, r);
        return dp[l][r];
    }
    if (dp[l][r].first != -1) return dp[l][r];
    
    pair<int, int> temp;
    if (s[l] == s[r]) {
        temp = recurse(s, l + 1, r - 1, dp);
        if (temp.first == l + 1 && temp.second == r - 1)
            dp[l][r] = make_pair(l, r); // can return after only! Since we know this is largest palindrome
        else
            dp[l][r] = temp;
    }
    temp = recurse(s, l + 1, r, dp);
    if (temp.first != -1 && temp.second - temp.first > dp[l][r].second - dp[l][r].first)
        dp[l][r] = temp;
    
    temp = recurse(s, l, r - 1, dp);
    if (temp.first != -1 && temp.second - temp.first > dp[l][r].second - dp[l][r].first)
        dp[l][r] = temp;
    
    return dp[l][r];
}

string longestPalindrome(string s) {
    vector<vector<pair<int, int>>> dp(s.length(), vector<pair<int, int>>(s.length(), make_pair(-1, -1)));
    
    pair<int, int> ans = recurse(s, 0, s.length()-1, dp);
    
    // for (int i = 0; i < s.length(); i++) {
    //     for (int j = 0; j < s.length(); j++)
    //         cout << dp[i][j].first << "/" << dp[i][j].second << "\t";
    //     cout << endl;
    // }
    // cout << endl;
    
    // cout << ans.first << "\t" << ans.second << endl;
    
    return s.substr(ans.first, ans.second - ans.first + 1);
}
*/

// Sol2 O(n^2) time, O(1) space (from hints)
string longestPalindrome(string s) {
    string ans = "";
    
    int l, r;
    // odd length palindromes
    for (int i = 0; i < s.length(); i++) {
        l = i; r = i;
        while (l >= 0 && r < s.length()) {
            if (s[l] != s[r]) break;
            if (ans.length() < r - l + 1)
                ans = s.substr(l, r - l + 1);
            l--; r++;
        }
    }
    
    // even length palindromes
    for (int i = 0; i < s.length(); i++) {
        l = i; r = i+1;
        while (l >= 0 && r < s.length()) {
            if (s[l] != s[r]) break;
            if (ans.length() < r - l + 1)
                ans = s.substr(l, r - l + 1);
            l--; r++;
        }
    }
    
    return ans;
}

// Sol1 O(n^2) time and space using dynamic programming
// Had to peek into the hints :( 
/*
string longestPalindrome(string s) {
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
    
    for (int i = 0; i < s.length(); i++) dp[i][i] = true;
    
    int max_val = 1, max_l = 0, max_r = 0;
    
    for (int i = s.length() - 2; i >= 0; i--) {
        for (int j = i+1; j < s.length(); j++) {
            if (s[i] == s[j]) {
                if (j - i == 1) dp[i][j] = true;
                else dp[i][j] = dp[i+1][j-1];
            }
            
            if (dp[i][j] && j - i + 1 >= max_val) {
                max_val = j - i + 1;
                max_l = i;
                max_r = j;
            }
        }
    }
    return s.substr(max_l, max_val);
}
*/

int main() {
	int t;
	cin >> t;
	
    while(t--) {
        string s;
        cin >> s;
        cout << longestPalindrome(s) << endl;
    }
	return 0;
}
