//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
long long int merge(long long int arr[], long long int low, long long int mid, long long int high) {
    long long int i = low, j = mid+1;
    long long int temp[high+1];
    long long int k = low;
    long long int inversions = 0;

    while(i <= mid and j <= high) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++, k++;
        }

        else {
            temp[k] = arr[j];
            inversions += (mid+1) - i;    // arr[k] ko (mid + 1 - i) elements se piche le jana padega
            j++, k++;
        }
    }

    while(i <= mid) {
        temp[k++] = arr[i++];
    }

    while(j <= high) {
        temp[k++] = arr[j++];
    }

    for(int d = low; d <= high; d++) {
        arr[d] = temp[d];
    }

    return inversions;
}

long long int mergeSort(long long int arr[], long long int low, long long int high) {
    long long int mid = (low+high)/2;
    long long int inversions = 0;

    if(low < high) {
        inversions += mergeSort(arr, low, mid);
        inversions += mergeSort(arr, mid+1, high);
        inversions += merge(arr, low, mid, high);
    }

    return inversions;
}

long long int inversionCount(long long arr[], long long N) {
    return mergeSort(arr,0,N-1);
}

};

//{ Driver Code Starts.

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
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends