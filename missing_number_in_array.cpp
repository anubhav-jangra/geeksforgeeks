// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int MissingNumber(vector<int>& array, int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];

        cout << MissingNumber(array, n) << "\n";
    }
    return 0;
}// } Driver Code Ends


// Sol3 (won't overflow): an update to Sol1
int MissingNumber(vector<int>& array, int n) {
    int sum = 1;
    
    for (int i = 2; i <= n; i++) {
        sum += i;
        sum -= array[i-2];
    }
    return sum;
}

// Sol2 (won't overflow)
/*
int MissingNumber(vector<int>& array, int n) {
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++)
        a ^= i;
    
    for (int i = 0; i < n-1; i++)
        b ^= array[i];
    
    return a^b;
}
*/

// Sol1 (can overflow)
/*
int MissingNumber(vector<int>& array, int n) {
    return (n*(n+1))/2 - accumulate(array.begin(), array.end(), 0);
}
*/
