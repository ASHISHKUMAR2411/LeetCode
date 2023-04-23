//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void merge(vector<int> &arr, int l, int mid, int r, int &count){
        int n1 = mid - l + 1;
        int n2 = r - mid;
        vector<int> arr1(n1, 0), arr2(n2, 0);
        for(int i = 0; i < n1; i++){
            arr1[i] = arr[i + l];
        }
        for(int i = 0; i< n2; i++){
            arr2[i] = arr[mid + 1 + i];
        }
        int i1 = 0, i2 = 0;
        while(i1 < n1 and i2 < n2){
            if(arr1[i1] > 2*arr2[i2]){
               count += n1 - i1;
               i2++;
            }
            else{
                i1++;
            }
        }
        i1 = 0, i2 = 0;
        int k = l;
        while(i1 < n1 and i2 < n2){
            if(arr1[i1] <= arr2[i2]){
                arr[k++] = arr1[i1++];
            }
            else{
                arr[k++] = arr2[i2++];
            }
        }
        while(i1 < n1){
            arr[k++] = arr1[i1++];
        }
        while(i2 < n2){
            arr[k++] = arr2[i2++];
        }
    }
    void mergeSort(vector<int> &arr, int l, int h, int &count){
        if(l < h){
            int mid = (l + h)/2;
            mergeSort(arr, l, mid, count);
            mergeSort(arr, mid + 1, h, count);
            merge(arr, l, mid, h, count);
        }
    }
    int countRevPairs(int n, vector<int> arr) {
        // Code here
        int count = 0;

        mergeSort(arr, 0, n-1, count);
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends