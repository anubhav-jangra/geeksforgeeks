#include <iostream>
#include <algorithm>
using namespace std;

// Sol1, after peeking into the hint a bit ;(
void printPermuatations(string s, int r) {
    if (r == s.length()) return; // should not happen though
    
    if (r == s.length() - 1) {
        cout << s << " ";
        return;
    }
    
    for (int i = r; i < s.length(); i++) {
        swap(s[i], s[r]);
        printPermuatations(s, r+1);
    }
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    string s;
	    cin >> s;
	    sort(s.begin(), s.end());
	    printPermuatations(s, 0);
	    cout << endl;
	}
	
	return 0;
}
