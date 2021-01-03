// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


// Sol3 (optimized sol2) O(n2)
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    sort(arr, arr+n);
	    
	    for (int i = 0; i < n; i++)
	        arr[i] *= arr[i];
	    
	    int start, end, sum;
	    for (int i = n-1; i >= 0; i--) {
	        start = 0; end = i-1;
	        while (start < end && sum != arr[i]) {
	            sum = arr[start] + arr[end];
	            if (sum > arr[i]) {
	                end--;
	            } else {
	                start++;
	            }
	        }
	        if (sum == arr[i])
	            return true;
	    }
	    
	    return false;
	}
};

// Sol2 O(n3)
/*
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    sort(arr, arr+n);
	    
	    for (int i = n-1; i >= 0; i--)
	        for (int j = 0; j < i; j++)
	            for (int k = j+1; k < i; k++)
	                if (arr[i] * arr[i] == arr[j] * arr[j] + arr[k] * arr[k])
	                    return true;
	    
	    return false;
	}
};
*/

// Optimized sol1
/*
vector<int> freq(1000001, 0);
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    
	    for (int i = 0; i < n; i++)
	        arr[i] *= arr[i];
	        
	    int max_val = *max_element(arr, arr+n);
	    for (int i = 0; i <= max_val; i++)
	        freq[i] = 0;
	    
	    for (int i = 0; i < n; i++)
	        freq[arr[i]] = 1;
	    
	    for (int i = 0; i < n; i++)
	        for (int j = i+1; j < n; j++) {
	            if (freq[arr[i]] && freq[arr[j]] && arr[i] + arr[j] < max_val && freq[arr[i] + arr[j]]) {
	                return true;
	            }
	        }
	    return false;
	}
};
*/

// Failed sol1 (This one works)
/*
vector<int> freq(1001, 0);
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    int max_val = *max_element(arr, arr+n);
	    
	    for (int i = 0; i < max_val; i++)
	        freq[i] = 0;
	    
	    for (int i = 0; i < n; i++)
	        freq[arr[i]]++;
	    
	    int temp;
	    for (int i = 0; i < n; i++)
	        for (int j = i+1; j < n; j++) {
	            temp = arr[i] * arr[i] + arr[j] * arr[j];
	            if (sqrt(temp) == floor(sqrt(temp)) && freq[sqrt(temp)]) {
	                // cout << "i: " << i << " j: " << j << " val: " << sqrt(temp) << endl;
	                return true;
	            }
	        }
	    return false;
	}
};
*/

// Failed sol1 
/*
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    int max_val = *max_element(arr, arr+n);
	    vector<int> freq(max_val+1, 0);
	    
	    for (int i = 0; i < n; i++)
	        freq[arr[i]]++;
	    
	    int temp;
	    for (int i = 0; i < n; i++)
	        for (int j = i+1; j < n; j++) {
	            temp = arr[i] * arr[i] + arr[j] * arr[j];
	            if (sqrt(temp) == floor(sqrt(temp)) && freq[sqrt(temp)]) {
	                // cout << "i: " << i << " j: " << j << " val: " << sqrt(temp) << endl;
	                return true;
	            }
	        }
	    return false;
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
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
  // } Driver Code Ends
