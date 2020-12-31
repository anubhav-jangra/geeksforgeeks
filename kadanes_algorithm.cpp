// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){
    
    int max_sum = 0, temp_sum = 0;
    
    // 
    for (int i = 0; i < n; i++) {
        temp_sum += arr[i];
        if (temp_sum < 0)
            temp_sum = 0;
        if (temp_sum > max_sum)
            max_sum = temp_sum;
    }
    
    // check if there was no positive element in the array altogether
    if (max_sum == 0) {
        return *max_element(arr, arr+n);
    }
    return max_sum;
}

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends
