// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return if the paranthesis are balanced or not
// Sol2 - optimized
bool ispar(string x)
{
    // Your code here
    stack<char> stk;
    for (int i = 0; i < x.length(); i++) {
        if (stk.empty()) {
            if (x[i] == ')' || x[i] == '}' || x[i] == ']')
                return false;
            stk.push(x[i]);
        }
        else if (x[i] == '}' && stk.top() == '{')
            stk.pop();
        else if (x[i] == ']' && stk.top() == '[')
            stk.pop();
        else if (x[i] == ')' && stk.top() == '(')
            stk.pop();
        else if (x[i] == ')' && stk.top() != '(')
            return false;
        else if (x[i] == ']' && stk.top() != '[')
            return false;
        else if (x[i] == '}' && stk.top() != '{')
            return false;
        else
            stk.push(x[i]);
    }
    if (stk.empty())
        return true;
    return false;
}

// Sol1 - unoptimized
/*
bool ispar(string x)
{
    // Your code here
    stack<char> stk;
    for (int i = 0; i < x.length(); i++) {
        if (stk.empty())
            stk.push(x[i]);
        else if (x[i] == '}' && stk.top() == '{')
            stk.pop();
        else if (x[i] == ']' && stk.top() == '[')
            stk.pop();
        else if (x[i] == ')' && stk.top() == '(')
            stk.pop();
        // else if (x[i] == ')' && stk.top() != '(')
        //     return false;
        // else if (x[i] == ']' && stk.top() != '[')
        //     return false;
        // else if (x[i] == '}' && stk.top() != '{')
        //     return false;
        else
            stk.push(x[i]);
    }
    if (stk.empty())
        return true;
    return false;
}
*/

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       if(ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
