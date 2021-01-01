// { Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// This function wants you to modify the given input
// array and no need to return anything
// arr: input array
// n: size of array

// Sol2 (a three pass)
void rearrange(long long *arr, int n) 
{
    long long N = *max_element(arr, arr+n) + 5;
    long long mid = ceil(n/2.0), min_idx = 0, max_idx = n-1;
    
    for (int i = 0; i < n; i++) {
        if (i%2 == 0) // even
            arr[i] += (arr[max_idx--] % N) * N;
        else // even
            arr[i] += (arr[min_idx++] % N) * N;
    }
    
	for (int i = 0; i < n; i++) {
        arr[i] /= N;
    }
}

// Sol1 (works fine) (four pass)
/*
void rearrange(long long *arr, int n) 
{ 
    if (n == 1)
        return;
    long long N = *max_element(arr, arr+n) + 5;
    long long mid = ceil(n/2.0);
    
    for (int i = mid-1; i >= 0; i--) {
        if (2*i+1 == n) 
            arr[2*i] += N*arr[i];
        else
            arr[2*i+1] += N*arr[i];
    }

    for (int i = n-1; i >= mid; i--) {
        arr[2*(n-1-i)] += N*(arr[i] % N);
    }
    
	for (int i = 0; i < n; i++) {
        arr[i] /= N;
    }
}
*/

// { Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        //calling rearrange() function
        rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 
  // } Driver Code Ends
