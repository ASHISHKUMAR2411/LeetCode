class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Using XOR to find the xor of the two number. 
        vector<int> ans(2, 0);
        long xor_ = 0;
        for(int i = 0; i< nums.size(); i++){
            xor_ ^= nums[i];
        }
        xor_ &= -xor_;
        for(int i = 0; i < nums.size(); i++){
            if((nums[i] & xor_ )){
                ans[0] ^= nums[i];
            }
            else{
                ans[1] ^= nums[i];
            }
        }
        return ans;
    }
};