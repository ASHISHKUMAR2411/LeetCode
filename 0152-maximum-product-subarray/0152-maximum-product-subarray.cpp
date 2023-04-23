class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN, p = 1;
        for(int i = 0; i < nums.size(); i++){
            p = p * nums[i];
            maxi = max(maxi, p);
            if(nums[i] == 0) p = 1;
        }
        p = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            p *= nums[i];
            maxi = max(maxi, p);
            if(nums[i] == 0) p = 1;
        }
        return maxi;
    }
};