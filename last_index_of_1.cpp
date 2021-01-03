#include <bits/stdc++.h>
using namespace std;

int findIndex(const string &s) {
    for (int i = s.length()-1; i >= 0; i--)
        if (s[i] == '1')
            return i;
    return -1;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    string s;
	    cin >> s;
	    cout << findIndex(s) << endl;
	}
	return 0;
}
