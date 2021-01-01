// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

// Sol3 O(n) time, O(1) space (saw in comments)
/*
int findPlatform(int arr[], int dep[], int n) {
    vector<int> info(2400, 0);
    
    for (int i = 0; i < n; i++) {
        info[arr[i]]++;
        info[dep[i] + 1]--;
    }
    
    for (int i = 1; i <= 2400; i++) {
        info[i] += info[i-1];
    }
    
    int max = 0;
    for (int i = 0; i <= 2400; i++)
        if (info[i] > max)
            max = info[i];
    
    return max;
}
*/

struct cmp {
    bool operator()(const pair<int, bool> &i1, const pair<int, bool> &i2) const {
        if (i1.first == i2.first) {
            if (i1.second)
                return false;
            else
                return true;
        } else 
            return (i1.first < i2.first);
    }
};

// Sol2 O(n) time, O(n) space (learnt from editorial) (Doesn't pass the case, probably because there is a clash in the test case)
// Made this solution pass, by ensuring that in the multimap, in case of any clash, the departure occurs first, and then the arrival happens
int findPlatform(int arr[], int dep[], int n) {
    multimap<pair<int, bool>, bool, cmp> info; // bool 0 -> arrival, bool 1 -> departure (notation)
    
    for (int i = 0; i < n; i++) {
        info.insert(make_pair(pair<int, bool>(arr[i], false), true));
        info.insert(make_pair(pair<int, bool>(dep[i], true), true));
    }
    
    int ans = 0, temp = 0;
    
    for (auto iter = info.begin(); iter != info.end(); iter++) {
        if (!iter->first.second) { // arrival
            temp++;
        } else { // departure
            temp--;
        }
        
        if (temp > ans)
            ans = temp;
    }
    
    return ans;
}

// Sol1 O(nlogn) time, O(n) space
/*
int anyFree(vector<int> plats, int start) {
    for (int i = 0; i < plats.size(); i++) {
        if (plats[i] < start)
            return i;
    }
    return -1;
}

int findPlatform(int arr[], int dep[], int n)
{
	// Your code here
	vector<pair<int, int>> info;
	for (int i = 0; i < n; i++) {
	    info.push_back(pair<int, int> (arr[i], dep[i]));
	}
	
	sort(info.begin(), info.end());
	
	vector<int> plats;
	
	for (int i = 0; i < n; i++) {
	    if (plats.empty()) {
	        plats.push_back(info[i].second);
	    } else {
	        int temp = anyFree(plats, info[i].first);
	        if (temp == -1) {
	            plats.push_back(info[i].second);
	        } else {
	            plats[temp] = info[i].second;
	        }
	    }
	}
	return plats.size();
}
*/

// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
           for(int i=0;i<n;i++)
        cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
    cout <<findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends
