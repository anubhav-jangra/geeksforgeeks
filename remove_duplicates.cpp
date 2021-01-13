// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Sol1 - O(n^2) time and O(n) space
class Solution{
public:	
	string removeDups(string S) {
	    string ans = "";
	    for (int i = 0; i < S.length(); i++)
	        if (ans.find(tolower(S[i])) == string::npos || ans.length() == 0) 
	            ans += S[i];
	        
	    return ans;
	}
};

// { Driver Code Starts.


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		
   		Solution ob;
   		cout << ob.removeDups(s) << "\n";
   		
   	}

    return 0;
}  // } Driver Code Ends
