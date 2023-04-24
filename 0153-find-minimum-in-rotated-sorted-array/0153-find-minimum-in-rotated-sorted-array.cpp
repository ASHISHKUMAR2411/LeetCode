class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int l = 0, h = nums.size() - 1;
        while(l <= h){
            int mid = (l + h)/2;
            mini = min(mini, nums[mid]);
            mini = min(mini, min(nums[l], nums[h]));
            if(nums[mid] > nums[l]){
                mini = min(mini, nums[l]);
                l = mid + 1;
            }
            else{
                mini = min(mini, nums[mid]);
                h = mid - 1;
            }
        }
        return mini;
    }
};