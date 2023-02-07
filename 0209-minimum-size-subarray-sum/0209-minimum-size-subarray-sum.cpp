class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, len = INT_MAX, sum = 0 ;
        while(l <= r and r <= nums.size() and l < nums.size()){
            if(sum < target){
                if(r == nums.size()) break;
                sum += nums[r];
                r++;
            }
            else if(sum >= target){
                len = min(len, r - l);
                sum -= nums[l];
                l++;
            }
        }
        // len = min(len, r-l + 1);
        return len == INT_MAX ? 0 : len;
    }
};