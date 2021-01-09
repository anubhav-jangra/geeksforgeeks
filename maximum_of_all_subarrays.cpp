// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// O(1) time and O(k) auxilary space solution (after taking hints!)
vector <int> max_of_subarrays(int *arr, int n, int k){
    vector<int> ans(n-k+1, -1);
    
    deque<int> q;
    
    q.push_back(0);
    for (int i = 1; i < k; i++) {
        while (!q.empty() && arr[i] > arr[q.back()])
            q.pop_back();

        q.push_back(i);
    }
    
    for (int i = k; i < n; i++) {
        ans[i-k] = arr[q.front()];
        
        if (q.front() == i-k)
            q.pop_front();
        
        while (!q.empty() && arr[i] > arr[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    ans[n-k] = arr[q.front()];
    return ans;
}


// Failed sol2
/*
vector <int> max_of_subarrays(int *arr, int n, int k){
    vector<int> ans(n-k+1, -1);
    
    set<int> q;
    
    for (int i = 0; i < k; i++) {
        q.insert(arr[i]);
    }
    
    for (int i = k-1; i < n; i++) {
        ans[i-(k-1)] = *q.rbegin();
        q.erase(arr[i-(k-1)]);
        q.insert(arr[i+1]);
    }
    return ans;
}
*/

// a trivial solution O(k*n) - time limit exceeded
/*
vector <int> max_of_subarrays(int *arr, int n, int k){
    vector<int> ans(n-k+1, -1);
    
    for (int i = k; i <= n; i++) {
       ans[i-k] = *max_element(arr+(i-k), arr+i);
    }
    
    return ans;
}
*/

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    
	    vector <int> res = max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
