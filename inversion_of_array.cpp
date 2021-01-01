// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

long long N_;
long long int counter;

void merge(long long arr[], long long l, long long mid, long long r) {
    vector<long long> temp;
    long long idx1 = l, idx2 = mid;
    while (idx1 < mid && idx2 <= r) {
        if (arr[idx1] > arr[idx2]) {
            temp.push_back(arr[idx2++]);
            counter += mid - idx1;
        } else {
            temp.push_back(arr[idx1++]);
        }
    }
    while (idx2 <= r)
        temp.push_back(arr[idx2++]);
    while (idx1 < mid)
        temp.push_back(arr[idx1++]);
    
    for (int i = l, idx1=0; i <= r; i++, idx1++) {
        arr[i] = temp[idx1];
    }
}

void mergeSort(long long arr[], long long l, long long r) {
    if (l >= r)
        return;
    long long mid = (r+l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    
    merge(arr, l, mid+1, r);
}

long long int inversionCount(long long arr[], long long N)
{
    counter = 0;
    N_ = N;
    // long long arr_back[N] = arr;
    mergeSort(arr, 0, N-1);
    
    return counter;
}


// Failed attempt-1
/*
long long int counter = 0;
long long N_;

long long partition(long long arr[], long long l, long long r) {
    long long p1 = l-1, val = arr[r];
    for (long long i = l; i < r; i++) {
        if (arr[i] > val) {
            continue;
        } else {
            swap(arr[++p1], arr[i]);
            // cout << "\ti: " << i << " p1: " << p1 << " total: " << i - p1 << endl;
            counter += i-p1;
        }
    }
    swap(arr[++p1], arr[r]);
    // cout << "\tr: " << r << " p1: " << p1 << " total: " << r - p1 << endl;
    counter += r-p1;
    return p1;
}

void quickSort(long long arr[], long long l, long long r){
    cout << "l: " << l << " r: " << r << endl;
    if (l >= r)
        return;
    long long p = partition(arr, l, r);
    cout << "p: " << p << " array is: ";
    for (int i = 0; i < N_; i++)
        cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, l, p-1);
    quickSort(arr, p+1, r);
}

long long int inversionCount(long long arr[], long long N)
{
    // N_ = N;
    // long long arr_back[N] = arr;
    quickSort(arr, 0, N-1);
    
    return counter;
}
*/


// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends