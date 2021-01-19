// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// Sol1 (hints from comments)
class Solution {
private:
public:
	int minSwaps(vector<int>&nums){
	    
	    int n = nums.size();
	    vector<pair<int, int>> sort_nums;
	    for (int i = 0; i < n; i++)
	        sort_nums.push_back(make_pair(nums[i], i));
	    
	    sort(sort_nums.begin(), sort_nums.end());
	    
	    // visited array
	    vector<bool> visited(n, false);
	    
	    int ans = 0, curr_ele;
	    for (int i = 0; i < n; i++) {
	        if (!visited[i] && sort_nums[i].second != i) {
	            curr_ele = i;
	            ans--; // total_swaps/cycle = # elements in cycle -1
	            
	            while (!visited[curr_ele]) {
	                ans++;
	                visited[curr_ele] = true;
	               // cout << "visiting " << temp << endl;z
	                
	                curr_ele = sort_nums[curr_ele].second;
	            }
	        }
	    }
	    
	    return ans;
	}
};

// Failed attempt 1 - Working fine on all the manual cases, but Runtime ErrorAbort signal from abort(3) (SIGABRT)
// Found out, it was taking O(V2 space), hence it was exceeding the memory limit
/*
class Solution {
private:
public:
	int minSwaps(vector<int>&nums){
	    
	    int n = nums.size();
	    vector<int> sort_nums = nums;
	    sort(sort_nums.begin(), sort_nums.end());
	    
	    // graph adjacency matrix
	    vector<vector<int>> adj (n, vector<int>(n, 0));
	    // visited array
	    vector<bool> visited(n, false);
	    
	    int pos;
	    for (int i = 0; i < n; i++) {
	        pos = lower_bound(sort_nums.begin(), sort_nums.end(), nums[i]) - sort_nums.begin();
	        
	        if (pos != i) {
	            adj[i][pos] = 1;
	           // cout << "created edge from se" << i << " to " << pos << endl;
	        } else
	            visited[i] = true;
	    }
	    
	    int ans = 0, curr_ele;
	    for (int i = 0; i < n; i++) {
	        if (!visited[i]) {
	            curr_ele = i;
	            ans--; // total_swaps/cycle = # elements in cycle -1
	            
	            while (!visited[curr_ele]) {
	                ans++;
	                visited[curr_ele] = true;
	               // cout << "visiting " << temp << endl;z
	                
	                for (int j = 0; j < n; j++) {
	                    if (adj[curr_ele][j] == 1 && !visited[j]) {
	                       // cout << "push(in): " << j << endl;
	                        curr_ele = j;
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    
	    return ans;
	}
};
*/


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
