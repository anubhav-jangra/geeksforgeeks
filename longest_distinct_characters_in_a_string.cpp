#include <iostream>
#include <vector>
using namespace std;

// Sol1 - O(n^2) solution
/*
int longestDistinctChars(string s) {
    vector<bool> alpha(26, false);
    
    int max_val = -1, curr_val = 0;
    for (int j = 0; j < s.length(); j++) {
        for (int i = j; i < s.length(); i++) {
            if (!alpha[s[i] - 'a']) {
                curr_val++;
                alpha[s[i] - 'a'] = true;
            }
            else {
                max_val = max(max_val, curr_val);
                curr_val = 0;
                alpha = vector<bool>(26, false);
                break;
            }
        }
    }
    
    return max_val;
}
*/

// Sol2 - O(n) solution
int longestDistinctChars(string s) {
    vector<int> alpha(26, -1);
    
    int max_val = -1, curr_val = 0, start = 0;
    for (int i = 0; i < s.length(); i++) {
        
        if (alpha[s[i] - 'a'] == -1) { // not encountered this alphabet yet
            curr_val++;
            alpha[s[i] - 'a'] = i;
        }
        else { // have already encountered this one
            max_val = max(max_val, curr_val);
            start = max(start, alpha[s[i] - 'a']);
            curr_val = i - start;
            alpha[s[i] - 'a'] = i;
        }
    }
    max_val = max(max_val, curr_val);
    
    return max_val;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    string s;
	    cin >> s;
	    cout << longestDistinctChars(s) << endl;
	}
	return 0;
}
