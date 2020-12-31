// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


// Sol5 (from comments)

void merge(int arr1[], int arr2[], int n, int m)
{
    int x=n-1, y = 0;
    while(x >= 0 && y < m) { 
        if(arr1[x] > arr2[y]){
            swap(arr1[x--] , arr2[y++]);
        }
        else
            break;
    }
    sort(arr1 , arr1+n);
    sort(arr2 , arr2+m);
}

// Sol4 O(m+n log(m+n))
/*
void merge(int arr1[], int arr2[], int n, int m) 
{
    int gap = ceil((m+n) / 2.0), r;
    
    while (true) {
        // cout << "gap: " << gap << " arr1: " ;
        // for (int l = 0; l < n; l++)
        //     cout << arr1[l] << " ";
        // cout << "arr2[i]: ";
        // for (int l = 0; l < m; l++)
        //     cout << arr2[l] << " ";
        // cout << endl;
        r = gap;
        for (int l = 0; l < m + n && r < m + n; l++, r++) {
            if (l < n && r >= n) { // l lies in first half & r lies in second half
                if (arr1[l] > arr2[r-n]) {
                    swap(arr1[l], arr2[r-n]);
                }
            } else if (l < n && r < n) { // l lies in first half & r lies in first half
                if (arr1[l] > arr1[r]) {
                    swap(arr1[l], arr1[r]);
                }
            } else if (l >= n && r >= n) { // l lies in second half & r lies in second half
                if (arr2[l-n] > arr2[r-n]) {
                    swap(arr2[l-n], arr2[r-n]);
                }
            } else { // l lies in second half & r lies in first half (not gonna happen case)
                cout << "BAZINGA\n";
            }
        }
        if (gap == 1)
            break;
        gap = ceil(gap/2.0);
    }
}
*/

// Sol3 O(m*n) (time limit exceeded)
/*
void merge(int arr1[], int arr2[], int n, int m) 
{
    int temp, k, j;
    for (int i = m-1; i >= 0; i--) {
        
        // cout << "i: " << i << " arr1: " ;
        // for (int l = 0; l < n; l++)
        //     cout << arr1[l] << " ";
        // cout << "arr2[i]: ";
        // for (int l = 0; l < m; l++)
        //     cout << arr2[l] << " ";
        // cout << endl;
        
        if (arr2[i] >= arr1[n-1]) { // this means that element arr[2] is inplace
            continue;
        } else { // this means arr1[n-1] is the largest one left
            temp = arr2[i];
            arr2[i] = arr1[n-1];
            
            // edge case of n = 1 or 2!! -> implicitly handled
            // cout << "\ttemp: " << temp << " k: " << k << endl;
            for (j = n-1; j >= 0 && arr1[j] >= temp; j--)
                arr1[j] = arr1[j-1];
            arr1[j+1] = temp;
        }
    }
}
*/

// Sol2 (Failed attempt) O(n*m*logn)
/*
void merge(int arr1[], int arr2[], int n, int m) 
{
    int temp, k, counter1 = n-1;
    for (int i = m-1; i >= 0; i--) {
        // cout << "i: " << i << " counter1: " << counter1 << " arr1: " ;
        // for (int l = 0; l < n; l++)
        //     cout << arr1[l] << " ";
        // cout << "arr2[i]: ";
        // for (int l = 0; l < m; l++)
        //     cout << arr2[l] << " ";
        // cout << endl;
        
        if (arr1[n-1] > arr1[counter1])
            counter1 = n-1;
        
        if (arr2[i] >= arr1[counter1]) { // this means that element arr[2] is inplace
            continue;
        } else { // this means arr1[counter1] is the largest one left
            temp = arr2[i];
            arr2[i] = arr1[counter1];
            // cout << "\ttemp: " << temp << endl;
            arr1[counter1] = temp;
            
            if(arr1[counter1] < arr1[counter1-1])
                counter1--;
        }
    }
    if (counter1 < n-1)
        sort(arr1, arr1+n);
}
*/
// Sol1 O(m*n*logn)
/*
int binSearch (int arr[], int n, int target) { // returns the index after which the target fits

    if (arr[0] >= target) // target is smaller than all the elements in arr 
            return -1;
    else if (target >= arr[n]) // target is greater than all the elements in arr 
        return n;

    int l = 0, r = n, mid;
    while (l < r) {
        mid = l + (r-l)/2;
        // cout << "\tl: " << l << " r: " << r << " mid: " << mid << endl;
        if (arr[mid] <= target && arr[mid+1] >= target)
            return mid;
        else if (arr[mid] > target)
            r = mid;
        else
            l = mid;
    }
}


void merge(int arr1[], int arr2[], int n, int m) 
{
    int temp, k;
    for (int i = m-1; i >= 0; i--) {
        
        // cout << "i: " << i << " arr1: " ;
        // for (int l = 0; l < n; l++)
        //     cout << arr1[l] << " ";
        // cout << "arr2[i]: ";
        // for (int l = 0; l < m; l++)
        //     cout << arr2[l] << " ";
        // cout << endl;
        
        if (arr2[i] >= arr1[n-1]) { // this means that element arr[2] is inplace
            continue;
        } else { // this means arr1[n-1] is the largest one left
            temp = arr2[i];
            arr2[i] = arr1[n-1];
            
            // edge case of n = 1 or 2!! -> implicitly handled
            // now search for the place where temp can fit in using binary search
            k = binSearch(arr1, n-2, temp); // n-2 since the last element is used up
            // cout << "\ttemp: " << temp << " k: " << k << endl;
            for (int j = n-1; j > k+1; j--)
                arr1[j] = arr1[j-1];
            arr1[k+1] = temp;
        }
    }
}
*/


// { Driver Code Starts.

int main() 
{ 
    
    int T;
    cin >> T;
    
    while(T--){
        int n, m;
        cin >> n >> m;
        
        int arr1[n], arr2[m];
        
        for(int i = 0;i<n;i++){
            cin >> arr1[i];
        }
        
        for(int i = 0;i<m;i++){
            cin >> arr2[i];
        }
        
        merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            printf("%d ", arr1[i]); 
        
       
        for (int i = 0; i < m; i++) 
            printf("%d ", arr2[i]); 
        
        cout<<endl;
    }

    return 0; 
} 
  // } Driver Code Ends