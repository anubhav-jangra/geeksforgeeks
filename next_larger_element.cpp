// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to store Next larger elements


vector <long long> nextLargerElement(long long arr[], int n){
    vector<long long> ans(n, 0);
    stack<long long> stk;
    
    for (int i = n-1; i >= 0; i--) {
        
        while (!stk.empty() && stk.top() < arr[i]) {
            stk.pop();
        }
        
        if (stk.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = stk.top();
        }
        stk.push(arr[i]);
    }
    
    return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        vector <long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
  // } Driver Code Ends
