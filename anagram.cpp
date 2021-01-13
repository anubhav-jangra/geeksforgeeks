// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if two strings are anagram
*   a, b: input string
*/
bool isAnagram(string a, string b) {
    
    if (a.length() != b.length()) return false; // make it a bit faster
    
    unordered_map<char, int> mp;
    
    for (int i = 0; i < a.length(); i++) {
        if (mp.find(a[i]) == mp.end()) mp[a[i]] = 1;
        else mp[a[i]]++;
    }
    
    for (int i = 0; i < b.length(); i++)
        mp[b[i]]--;
    
    for (auto it = mp.begin(); it != mp.end(); it++)
        if (it->second != 0) return false;
    
    return true;
}


// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;

        if(isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
  // } Driver Code Ends
