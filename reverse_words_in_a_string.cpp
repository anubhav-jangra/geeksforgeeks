// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s);
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        cout<<reverseWords(s)<<endl;
    }
}// } Driver Code Ends


string reverseWords(string S) 
{ 
    // code here 
    vector<string> stk;
    string temp;
    for (int i = 0; i < S.length(); i++) {
        temp = "";
        while (S[i] != '.' && i < S.length()) {
            temp += S[i];
            i++;
        }
        stk.push_back(temp);
    }
    S = stk.back();
    stk.pop_back();
    while (stk.size() > 0) {
        S += ".";
        S += stk.back();
        stk.pop_back();
    }
    
    return S;
} 
