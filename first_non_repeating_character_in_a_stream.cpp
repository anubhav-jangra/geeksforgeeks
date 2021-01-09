#include <bits/stdc++.h>
using namespace std;

bool findInQueue(queue<char> q, int target) {
    while (!q.empty()) {
        if (q.front() == target)
            return true;
        q.pop();
    }
    return false;
}

void deleteFromQueue(queue<char> &q, int target) {
    queue<char> q2;
    while (q.front() != target) {
        q2.push(q.front());
        q.pop();
    }
    
    q.pop();
    
    while (!q.empty()) {
        q2.push(q.front());
        q.pop();
    }
    
    while (!q2.empty()) {
        q.push(q2.front());
        q2.pop();
    }
}

void doStuff(vector<char> &arr) {
    
    queue<char> non_repeat;
    unordered_set<char> elements_visited;
    
    for (int i = 0; i < arr.size(); i++) {
        // cout << "\ni: " << i << " ";
        if (elements_visited.find(arr[i]) == elements_visited.end()) {
            // found a new element
            non_repeat.push(arr[i]);
            elements_visited.insert(arr[i]);
            cout << non_repeat.front() << " ";
        } else {
            // the element exists
            
            // if it is in the non_repeat, not it will be in the repeat part
            if (findInQueue(non_repeat, arr[i]))
                deleteFromQueue(non_repeat, arr[i]);    // remove it!
            
            if (non_repeat.empty())
                cout << -1 << " ";
            else
                cout << non_repeat.front() << " ";
        }
    }
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    
	    vector<char> arr(n, '.');
	    for (int i = 0; i < n; i++)
	        cin >> arr[i];
	    
	    doStuff(arr);
	    cout << endl;
	}
	return 0;
}
