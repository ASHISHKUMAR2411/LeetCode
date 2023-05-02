class Solution {
public:
    bool Search(vector<int> &A , int el){
        int b = 0, l = A.size() - 1, mid;
        while (b < l)
        {
            mid = (b + l) / 2;
            if (A[mid] == el)
            {
                return true;
            }
            else if (A[mid] > el)
            {
                l = mid - 1;
            }
            else
            {
                b = mid + 1;
            }
        }
        return false;
    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[0] >= nums.size()) return nums.size();
        int low = 1, high = nums.size() - 1, mid;
        while(low<=high){
            mid = (low + high)/2;
            if(nums[mid] >= (nums.size() - mid) && nums[mid - 1] < (nums.size() - mid)){
                return nums.size() - mid;
            }
            else if(nums[mid] >= (nums.size() - mid)){
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
};