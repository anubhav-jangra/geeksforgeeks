// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution {
public:
    vector<int> kthLargest(int k, int arr[], int n) {
        
        vector<int> ans;
        priority_queue<int> pq;
        
        for (int i = 0; i < k - 1; i++) {
            ans.push_back(-1);
            pq.push(arr[i] * -1);
        }
        
        pq.push(arr[k-1] * -1);
        ans.push_back(-1 * pq.top());
        
        for (int i = k; i < n; i++) {
            if (arr[i] < -1 * pq.top())
                ans.push_back(-1 * pq.top());
            else {
                pq.pop();
                pq.push(arr[i] * -1);
                ans.push_back(-1 * pq.top());
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
