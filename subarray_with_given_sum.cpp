#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Sol3 handles negative cases as well, and O(1) extra space
pair<int, int> find_subarray(vector<int> &arr, int target) {
    // find the smallest element in the array
    int min_ele = *min_element(arr.begin(), arr.end());
    
    // add this element to the entire array
    for (int i = 0; i < arr.size(); i++) {
        arr[i] += abs(min_ele);
    }
    
    int cumsum = arr[0], start = 0, end;
    
    // now run the simple algorithm, but change the sum accordingly
    for (end = 1; end <= arr.size(); end++) {
        
        while (cumsum > target + abs(min_ele) * (end-start) && start < end-1)  {
            cumsum -= arr[start++];
        }
        
        if (cumsum == target + abs(min_ele) * (end-start))
            return pair<int, int> (start, end-1);
        
        cumsum += arr[end];
    }
    return pair<int, int>(-1, -1);
}

// Sol2 handles negative cases, but couldn't pass due to time limit exceeded, also uses O(n) extra space
/*
pair<int, int> find_subarray(vector<int> &arr, int target) {
    unordered_map<int, int> mp;
    int cum_sum = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        
        cum_sum += arr[i];
        
        if (target == cum_sum) { // a sub_array starting from 0
            return pair<int, int> (0,i);
        }
        
        if (mp.find(cum_sum-target) != mp.end()) { // a subarray ending with 5 is found
            return pair<int, int> (mp[cum_sum-target] + 1, i);
        }
        
        mp.insert(pair<int, int> (cum_sum, i));
    }
    return pair<int, int> (-1,-1);
}
*/

// Sol1 O(n)
// doesn't handle negative numbers!
/*
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
*/

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
