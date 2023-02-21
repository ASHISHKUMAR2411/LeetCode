class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int y = 0;
        for(int i  =0; i < nums.size(); i++){
            y ^= nums[i];
        }
        return y;
    }
};