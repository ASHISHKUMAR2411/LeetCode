class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0, prev = nums[nums.size() - 1];
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i+1] < nums[i]){
                count++;
                prev = nums[i];
            }
        }
        if(count == 0) return true;
        return count == 1 and nums[0] >= nums[nums.size() - 1] ;
    }
};