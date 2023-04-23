class Solution {
public:
    void merge(vector<int> &nums, int l, int mid, int h, int &count){
        int n1 = mid - l + 1;
        int n2 = h - mid;
        vector<int> arr1(n1, 0), arr2(n2, 0);
        for(int i = 0 ; i < n1; i++){
            arr1[i] = nums[l + i];
        }
        for(int i = 0; i < n2; i++){
            arr2[i] = nums[mid + 1 + i];
        }
        int i1 = 0, i2 = 0; 
        while(i1 < n1 and i2 < n2){
            if(arr1[i1] > 2 *1ll* arr2[i2]){
                i2++;
                count += n1 - i1;
            }
            else{
                i1++;
            }
        }
        i1 = 0, i2 = 0;
        int k = l;
        while(i1 < n1 and i2 < n2){
            if(arr1[i1] <= arr2[i2]){
                nums[k++] = arr1[i1++];
            }
            else{
                nums[k++] = arr2[i2++];
            }
        }
        while(i1 < n1){
            nums[k++] = arr1[i1++];
        }
        while(i2 < n2){
            nums[k++] = arr2[i2++];
        }
        
    }
    void mergeSort(vector<int> &nums, int l, int h, int &count){
        if(l < h){
            int mid = (l + h)/2;
            mergeSort(nums, l , mid, count);
            mergeSort(nums, mid + 1, h, count);
            merge(nums,l , mid, h, count);
        }
    }
    int reversePairs(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        mergeSort(nums, 0, n-1, count);
        return count;
    }
};