#include <bits/stdc++.h>
using namespace std;

// Sol3 (from editorials) using stack O(n) time, O(n) space
int waterCapacity(const vector<int> &vec) {
    stack<int> stk;
    int ans = 0, h, dist;
    for (int i = 0; i < vec.size(); i++) {
        // cout << "i: " << i << endl;
        // pop elements until either the stack is not empty, and the top element is bigger than the current one
        while (!stk.empty() && vec[stk.top()] < vec[i]) {
            h = vec[stk.top()];
            stk.pop();
            if (stk.empty())
                break;
            dist = i - stk.top() - 1;
            ans += dist * (min(vec[stk.top()], vec[i]) - h);
            // cout << "h: " << h << " left: " << vec[stk.top()] << " right: " << vec[i] << " distance: " << i - stk.top() - 1 << " ans: " << ans << endl;
        }
        stk.push(i);
    }
    return ans;
}


// Sol2 (from editorials) O(n) time, O(1) space
/*
int waterCapacity(const vector<int> &vec) {
    if (vec.size() == 1 || vec.size() == 2 || vec.size() == 0)
        return 0;
        
    int water = 0, temp = 0, prev_idx = 0;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[prev_idx] <= vec[i]) { // new bigger height found
            prev_idx = i;
            temp = 0;
        } else {
            water += vec[prev_idx] - vec[i];
            temp  += vec[prev_idx] - vec[i];
        }
    }
    
    if (prev_idx == vec.size() - 1) 
        return water;
    
    water -= temp;
    // cout << "water: " << water << endl;
    
    int prev_idx2 = vec.size()-1;
    
    for (int i = vec.size() - 2; i >= prev_idx; i--) {
        if (vec[prev_idx2] <= vec[i]) {
            prev_idx2 = i;
        } else {
            water += vec[prev_idx2] - vec[i];
        }
    }
    return water;
}
*/

// Sol1 (saw first hint) O(n) time, O(n) space
/*
int waterCapacity(const vector<int> &vec) {
    vector<int> prefix(vec.size(), 0), suffix(vec.size(), 0);
    
    prefix[0] = vec[0];
    for (int i = 1; i < vec.size(); i++)
        prefix[i] = max(vec[i], prefix[i-1]);
    
    suffix[vec.size()-1] = vec[vec.size()-1];
    for (int i = vec.size() - 2; i >= 0; i--)
        suffix[i] = max(vec[i], suffix[i+1]);
        
    int water = 0;
    for (int i = 0; i < vec.size(); i++) {
        water += min(prefix[i], suffix[i]) - vec[i];
    }
    
    return water;
}
*/

// Failed attempt 1
/*
int waterCapacity(const vector<int> &vec) {
    // Handle edge cases of 1 and 0 vec size!
    
    int water = 0, height = 0, start = 0, end = vec.size()-1, nextl = 1, nextr = vec.size()-2;
    bool toggle = true; // try to remove and see if this works!
    
    while (nextl <= nextr) {
        if (height < min(vec[start], vec[end])) {
            water += (min(vec[start], vec[end]) - height)  * (end - start - 1);
            // cout << "Water updated to: " << water << " height to: " << min(vec[start], vec[end]) << " / " << min(vec[start], vec[end]) - height << " " << (end - start - 1) << endl;
            height = min(vec[start], vec[end]);
        }
        
        if (toggle) { // move nextl one step to right
        // cout << "nextl: " << nextl;
            if (vec[nextl] < vec[start]) {
                water -= min(vec[nextl], height); // decrease the height of this particular tower
            } else { // need to update the start
                water -= height; // decrease the height of water so far
                start = nextl;
            }
            // cout << " water: " << water << endl;
            nextl++;
            toggle = false;
        } else { // move nextr one step left
            // cout << "nextr: " << nextr;
            if (vec[nextr] < vec[end]) {
                water -= min(vec[nextr], height);
            } else {
                water -= height;
                end = nextr;
            }
            // cout << " water: " << water << endl;
            nextr--;
            toggle = true;
        }
    }
    return water;
}
*/

int main() {
	int t;
	cin >> t;
	int n;
	while (t--) {
	    cin >> n;
	    vector<int> vec(n, 0);
	    for (int i = 0; i < n; i++)
	        cin >> vec[i];
	    
	    cout << waterCapacity(vec) << endl;
	}
	return 0;
}
