// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */

// Sol1 O(n^2) time, O(1) space
int strstr(string s, string x) {
    int p_s, p_x;
     for (int i = 0; i < s.length(); i++) {
         if (s[i] == x[0]) {
             p_s = i+1;
             p_x = 1;
             while (p_x < x.length() && p_s < s.length() && s[p_s] == x[p_x]) {
                 p_s++;
                 p_x++;
             }
             if (p_x == x.length()) return i;
         }
     }
     return -1;
}
