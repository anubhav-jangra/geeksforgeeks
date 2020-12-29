#include <iostream>
#include <vector>
using namespace std;


// doesn't handle negative numbers!
pair<int, int> find_subarray(vector<int> &arr, int target) {
    int cumsum = 0, start = 0, end;
    
    // now do the detection
    for (end = 0; end < arr.size(); end++) {
        if (cumsum < target) {
            cumsum += arr[end];
        } else if (cumsum == target)
            return pair<int, int> (start, end);
        
        while (cumsum > target) 
            cumsum -= arr[start++];
            
        if (cumsum == target)
            return pair<int, int> (start, end);
    }
    return pair<int, int>(-1, -1);
}

int main() {
	//code
	int t, n, s, temp;
	cin >> t;
	while (t--) {
	    cin >> n >> s;
	    vector<int> arr;
	    for(int i = 0; i < n; i++) {
	        cin >> temp;
	        arr.push_back(temp);
	    }
	    
	    pair<int, int> ans = find_subarray(arr, s);
	    if (ans.first == -1)
	        cout << -1 << endl;
	    else
	        cout << ans.first + 1 << " " << ans.second + 1 << endl;
	}
	return 0;
}
