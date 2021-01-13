// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if str1 can be formed from
*   str2 after rotation by 2 places
*/
// O(n) time and O(1) space solution
bool isRotated(string str1, string str2) {
    
    int n = str1.length();
    
    // handle the edge cases
    if (str1.length() != str2.length()) return false;
    if (n < 3 && str1 == str2) return true;
    
    int i;
    // check for clockwise rotation (last two in first two)
    if (str1[n-2] == str2[0] && str1[n-1] == str2[1])
        for (i = 0; i < n - 2; i++)
            if (str1[i] != str2[i+2])
                break;
    if (i == n-2) return true;
    
    // check for anti-clockwise rotation (first two in last two)
    if (str2[n-2] == str1[0] && str2[n-1] == str1[1])
        for (i = 0; i < n - 2; i++)
            if (str2[i] != str1[i+2])
                break;
    if (i == n-2) return true;
    
    return false;
}


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		cout<<isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
