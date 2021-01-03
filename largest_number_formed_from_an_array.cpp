// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

// Sol1 (saw comments)
bool comp(const string &a, const string &b) {
    return b + a < a + b;
}

//User function template for C++
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(vector<string> &arr) {
	    sort(arr.begin(), arr.end(), comp);
	    
	    string s = "";
	    for (int i = 0; i < arr.size(); i++) {
	        s += arr[i];
	    }

	    return s;
	}
};

// Failed Sol1
/*
bool comp(const string &a, const string &b) {
    int i;
    for (i = 0; i < min(a.length(), b.length()); i++) {
        if (a[i] == b[i]) {
            continue;
        } else {
            return (a[i] > b[i]);
        }
    }
    if (i == min(a.length(), b.length())) {
        if (a.length() < b.length()) {
            return (b[i] < a[0]);
        } else {
            return (b[0] < a[i]);
        }
    }
}

//User function template for C++
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(vector<string> &arr) {
	    sort(arr.begin(), arr.end(), comp);
	    
	    string s = "";
	    for (int i = 0; i < arr.size(); i++) {
	        s += arr[i];
	    }

	    return s;
	}
};
*/


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
