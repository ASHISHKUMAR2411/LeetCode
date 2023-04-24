class Solution {
public:
    int bs(vector<int> &nums, int l, int h){
        if(l > h) return -1;
        int mid = (h + l)/2;
        if(mid > l and mid < h and nums[mid - 1] < nums[mid] and nums[mid] > nums[mid + 1]){
            return mid;
        }
        else{
            int l1 = bs(nums, l, mid - 1);
            if(l1 != -1) return l1;
            int l2 = bs(nums, mid + 1, h);
            if(l2 != -1) return l2;  
        }
        return -1;
    }
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        if(arr[0] > arr[1]) return 0;
        if(arr[n-1] > arr[n-2]) return n-1;
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == n - 1 || arr[mid] >= arr[mid + 1])) {
                // found peak element
                return mid;
            }
            else if (mid > 0 && arr[mid - 1] > arr[mid]) {
                // search left half
                end = mid - 1;
            }
            else {
                // search right half
                start = mid + 1;
            }
        }
        return -1;
    }
};