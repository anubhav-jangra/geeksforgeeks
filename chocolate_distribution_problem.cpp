#include <bits/stdc++.h>
using namespace std;

long long int minDifference(vector<long long int> &arr, int m) {
    
    sort(arr.begin(), arr.end());
    
    long long int min_val = INT_MAX, temp;
    for (int i = 0; i + m - 1 < arr.size(); i++) {
        temp = arr[i+m-1] - arr[i];
        if (temp < min_val)
            min_val = temp;
    }
    return min_val;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    int n;
	    cin >> n;
	    
	    vector<long long int> arr(n, 0);
	    for (int i = 0; i < n; i++)
	        cin >> arr[i];
	    
	    int m;
	    cin >> m;
	    
	    cout << minDifference(arr, m) << endl;
	}
	return 0;
}
