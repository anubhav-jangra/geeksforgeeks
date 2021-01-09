// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

// Solution using DP O(n2) time, O(1) space (after looking at the hints)

bool compFunc(const struct val &p1, const struct val &p2) {
    if (p1.first == p2.first) 
        return (p1.second < p2.second);
        
    return (p1.first < p2.first);
}

// You are required to complete this method
int maxChainLen(struct val p[], int n) {
    
    if (n == 1)
        return 1;
    
    sort(p, p + n, compFunc);
    
    vector<int> dp(n, 1);
    
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (p[i].first > p[j].second && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
                
    return dp[n-1];
}

// A greedy O(nlogn) solution, O(1) space: (after checking in comments :| )
/*
bool compFunc(const struct val &p1, const struct val &p2) {
    // if (p1.first == p2.first) 
    //     return (p1.second < p2.second);
        
    return (p2.second > p1.second);
}

// You are required to complete this method
int maxChainLen(struct val p[], int n) {
    
    if (n == 1)
        return 1;
    
    sort(p, p + n, compFunc);
    
    int ans = 1;
    struct val prev = p[0];
    for (int i = 1; i < n; i++)  {
        if (p[i].first > prev.second) {
            prev = p[i];
            ans++;
        }
    }
    return ans;
}
*/
