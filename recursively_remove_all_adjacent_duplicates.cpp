#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Failed Sol1 - O(n) time and O(n) space using stack
/*
void removeRecursively(string &s) {
    stack<char> stk;
    for (int i = 0; i < s.length(); i++) {
        if (!stk.empty() && stk.top() == s[i]) {
            
            while (stk.top() == s[i]) i++;
            i--;
            stk.pop();
        } else {
            stk.push(s[i]);
        }
    }
    s = "";
    while(!stk.empty()) {
        s += stk.top();
        stk.pop();
    }
    
    reverse(s.begin(), s.end());
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    string s;
	    cin >> s;
        removeRecursively(s);
	    cout << s << endl;
	}
	return 0;
}
*/

// O(n^3) solution
void removeRecursively(string &s, int n) {
    if (n <= 0) return;
    int i = n-1;
    while (s[i] == s[n]) i--;
    
    if (i != n-1) s.erase(i+1, n-i);
    removeRecursively(s, i);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    string s, temp;
	    cin >> s;
	    do {
	        temp = s;
	        removeRecursively(s, s.length()-1);
	    } while (temp != s);
	    cout << s << endl;
	}
	return 0;
}

