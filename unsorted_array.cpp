#include <bits/stdc++.h>
using namespace std;

// returns the index of element such that all elements left to it are smaller, and all elements right are larget than it
int findElement(vector<int> &arr) {
    vector<int> prefix(arr.size(), 0), suffix(arr.size(), 0);
    
    // store the largest element so far in the prefix
    prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); i++)
        prefix[i] = max(arr[i], prefix[i-1]);
        
    // store the smallest element from this point in the suffix
    suffix[arr.size()-1] = arr[arr.size()-1];
    for (int i = arr.size()-2; i >= 0; i--)
        suffix[i] = min(arr[i], suffix[i+1]);
    
    for (int i = 1; i < arr.size()-1; i++) {
        if (arr[i] >= prefix[i-1] && arr[i] <= suffix[i+1])
            return arr[i];
    }
    
    // no such element found
    return -1;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n;
	    cin >> n;
	    
	    vector<int> arr(n, 0);
	    for (int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    
	    cout << findElement(arr) << endl;
	}
	return 0;
}
