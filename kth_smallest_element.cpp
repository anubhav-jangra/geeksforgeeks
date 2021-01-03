// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int *, int, int, int);
 
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}// } Driver Code Ends

// Sol2 - O(n) - but the constants are huge in this case!
int partition (int arr[], int l, int r, int x) { // partition about value x after finding it
    for (int i = l; i <= r; i++)
        if (arr[i] == x) {
            swap(arr[i], arr[r]);
            break;
        }

    int val = arr[r], j = l-1;
    for (int i = l; i <= r-1; i++) {
        if (arr[i] < val) {
            swap(arr[i], arr[++j]);
        }
    }
    swap(arr[r], arr[++j]);
    return j;
}

int findMedian(int arr[], int n) 
{ 
    sort(arr, arr+n);  // Sort the array 
    return arr[n/2];   // Return middle element 
} 

int kthSmallest(int arr[], int l, int r, int k) {
    // cout << "l: " << l << " r: " << r << " k: " << k << endl;
    if (k == 0 || k > r-l+1)
        return -1;
    int i, idx = 0, n = r - l + 1;
    int medians[(n + 4)/5];
    
    // sorting array in bits of constant time, taking overall O(n) time
    
    // From the editorial: 
    // for (idx = 0; idx < n/5; idx++) {
    //     medians[idx] = findMedian(arr + l + idx * 5, 5); 
    // }
    // if (idx * 5 < n) //For last group with less than 5 elements 
    // { 
    //     medians[idx] = findMedian(arr + l + idx *5, n%5);  
    //     idx++; 
    // }
    
    for (i = l; i+5 <= r; i += 5) {
        sort(arr + i, arr + i + 5);
        medians[idx++] = arr[i+2];
    }
    if (i != r) { // if there is something left (n is not a complete multiple of 5)
        sort(arr + i, arr + r + 1);
        medians[idx++] = arr[(i + r) / 2];
    }
    
    // cout << "array is: ";
    // for (int i = l; i <= r; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // cout << "median array size: " << idx << endl; 
    
    
    int median = (idx == 1) ? medians[0] : kthSmallest(medians, 0, idx - 1, idx / 2);
    // cout << "\tmedian: " << median << endl;
    int p = partition(arr, l, r, median);
    
    if (p-l == k-1)
        return arr[p];
    else if (p-l > k-1) 
        return kthSmallest(arr, l, p-1, k);
    else
        return kthSmallest(arr, p+1, r, k-p+l-1);
}

// Sol1 - O(nlogn) worst case time complexity / O(n) expected time complexity
/*
int partition (int arr[], int l, int r) {
    if (r == l)
        return r;
    int random_idx = l + rand() % (r-l);
    swap(arr[r], arr[random_idx]);
    int val = arr[r], j = l-1;
    for (int i = l; i <= r-1; i++) {
        if (arr[i] < val) {
            swap(arr[i], arr[++j]);
        }
    }
    swap(arr[r], arr[++j]);
    return j;
}

//User function template for C++
// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int arr[], int l, int r, int k) {
    if (l > r) 
        return -1;
    int p = partition(arr, l, r);
    if (p == k-1)
        return arr[p];
    else if (p > k-1) 
        return kthSmallest(arr, l, p-1, k);
    else
        return kthSmallest(arr, p+1, r, k);
}
*/