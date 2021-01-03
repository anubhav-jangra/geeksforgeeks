// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

class Solution{
public:
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        int buy = -1;
        vector<vector<int> > ans;
        for (int i = 0; i < n; i++) {
            if (buy == -1) {
                buy = i;
            } else if (A[buy] < A[i]) { // a profit is bound to occur
                if (i != n-1) { // not the last day 
                    if (A[i] > A[i+1]) { // stocks fall next day, hence sell them
                        ans.push_back(vector<int>{buy, i});
                        buy = i+1;
                    }
                } else { // last day
                    ans.push_back(vector<int>{buy,i});
                }
            } else { // there is a better price to purchase the stocks right now
                buy = i;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            for (int i=0; i<ans.size(); ++i){
                cout<<"("<<ans[i][0]<<" "<<ans[i][1]<<") ";
            }
        }cout<<endl;
    }
    return 0;
}

  // } Driver Code Ends
