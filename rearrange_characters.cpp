#include <bits/stdc++.h>
using namespace std;

// Sol2 - similar to Sol1, with a small nuance
string doStuff(string s) {
    vector<int> freq(26, 0);
    
    for (int i = 0; i < s.length(); i++)
        freq[s[i] - 'a']++;
    
    int max_freq = 0;
    priority_queue<pair<int, char>> pq;
    for (int i = 0; i < 26; i++)
        if (freq[i] > 0) 
            pq.push(make_pair(freq[i], 'a'+i));
    
    pair<int, char> temp, last_entry, bad_entry = pair<int, char>(INT_MIN, '9');
    last_entry = bad_entry;
    string ans = "";
    while (!pq.empty()) {
        
        temp = pq.top();
        pq.pop();
        
        ans += temp.second;
        
        if (last_entry != bad_entry) pq.push(last_entry);
        
        if (--temp.first > 0) last_entry = temp;
        else last_entry = bad_entry;
    }
    
    return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    string s;
	    cin >> s;
	    string out_s = doStuff(s);
	    if (out_s.length() != s.length())
	        cout << 0 << endl;
	    else
	        cout << 1 << endl;
	}
	return 0;
}

// Sol1 
/*
string doStuff(string s) {
    vector<int> freq(26, 0);
    
    for (int i = 0; i < s.length(); i++)
        freq[s[i] - 'a']++;
    
    int max_freq = 0;
    priority_queue<pair<int, char>> pq;
    for (int i = 0; i < 26; i++)
        if (freq[i] > 0) 
            pq.push(make_pair(freq[i], 'a'+i));
    
    pair<int, char> temp;
    queue<pair<int, char>> temp_q;
    string ans = "";
    while (!pq.empty()) {
        while (!pq.empty() && ans != "" && pq.top().second == ans[ans.length()-1]) {
            temp = pq.top();
            pq.pop();
            temp_q.push(temp);
        }
        if (pq.empty()) 
            return "-1";
        
        temp = pq.top();
        pq.pop();
        
        while(!temp_q.empty()) {
            pq.push(temp_q.front());
            temp_q.pop();
        }
        
        ans += temp.second;
        if (--temp.first > 0) pq.push(temp);
    }
    return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
	    string s;
	    cin >> s;
	    string out_s = doStuff(s);
	    if (out_s == "-1")
	        cout << 0 << endl;
	    else
	        cout << 1 << endl;
	}
	return 0;
}
*/
