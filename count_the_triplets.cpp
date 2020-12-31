// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    // sort the array
	    sort(arr, arr+n);
	    
	    int start = 0, end = n-2, count = 0, last = n;
	    
	    while (--last >= 2) {
	        start = 0, end = last-1;
    	    while (start < end) {
    	        if (arr[start] + arr[end] == arr[last]) {
    	            count++; start++; end--;
    	        } else if (arr[start] + arr[end] > arr[last]) {
    	            end--;
    	        } else {
    	            start++;
    	        }
    	    }
	    }
	    return count;
	}
};

// Sol1 (using permuatation and combination) O(n^2) time, and O(max_element) space
// Works for clashing values as well!
/*
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    // create a frequency array
	    int max_ele = *max_element(arr, arr+n), ans = 0;
	    
	    vector<int> freq(max_ele+1, 0);
	    
	    // populate the freq table
	    for (int i = 0; i < n; i++)
	        freq[arr[i]]++;
	    
	    // compute triplets <0,0,0> -> nC3
	    ans += freq[0] * (freq[0] - 1) * (freq[0] - 2) / 6;
	    
	    // compute the triples <x,x,0> | x>0 -> #0 * (#n)C2
	    for (int i = 1; i <= max_ele; i++)
	        ans += freq[0] * freq[i] * (freq[i] - 1) / 2;
	        
	    // compute the triplets <x, x, 2x>
	    for (int i = 0; 2 * i <= max_ele; i++) 
	        ans += freq[i] * (freq[i] - 1) / 2 * freq[2*i];
	       
	    // compute the triplets <x, y, x+y>
	    for (int i = 1; i <= max_ele; i++)
	        for (int j = i+1; i+j <= max_ele; j++)
	            ans += freq[i] * freq[j] * freq[i+j];

	    return ans;
	}
};
*/

// { Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // } Driver Code Ends
