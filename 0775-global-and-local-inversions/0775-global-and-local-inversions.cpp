typedef long long ll;
long long ans = 0;

class Solution {
public:
    // void merge(vector<int> &arr, int lo, int mid, int hi) {
    //     int n1 = mid-lo+1, n2 = hi-mid;
    //     int arr1[n1], arr2[n2];
    //     for(ll i=0; i<n1; i++) arr1[i] = arr[lo+i];
    //     for(ll i=0; i<n2; i++) arr2[i] = arr[mid+i+1];
    //     int i=0, j=0, k=lo;
    //     while(i<n1 && j<n2) {
    //         if(arr1[i]<=arr2[j]) arr[k++] = arr1[i++];
    //         else {
    //             ans += n1 - i; // Only this line added in merge sort code
    //             arr[k++] = arr2[j++];
    //         }
    //     }
    //     while(i<n1) arr[k++] = arr1[i++];
    //     while(j<n2) arr[k++] = arr2[j++];
    // }
    // void mergeSort(vector<int> &arr, int lo, int hi) {
    //     if(lo<hi) {
    //         int mid = lo + (hi-lo)/2;
    //         mergeSort(arr, lo, mid);
    //         mergeSort(arr, mid+1, hi);
    //         merge(arr, lo, mid, hi);
    //     }
    // }
    bool isIdealPermutation(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(abs(nums[i] - i) > 1) return false;
        }
        return true;
        // long long local = 0;
        // for(int i = 0; i < nums.size()-1; i++){
        //     if(nums[i] > nums[i+1]){
        //         local++;
        //     }
        // }
        // ans = 0;
        // int N = nums.size();
        // mergeSort(nums, 0, N-1);
        // if(ans == local) return true;
        // else return false;
    }
};