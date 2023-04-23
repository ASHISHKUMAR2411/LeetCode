class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       if(nums.size() == 0) return {-1, -1};
        if(nums[0] > target) return {-1, -1};
        if(nums[nums.size() - 1] < target) return {-1, -1};
        int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(nums[start] != target){
            return {-1, -1};
        }
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        if(end >= 0 and nums[end] != target){
            return {-1, -1};
        }
        return {start, end};
        
    }
};