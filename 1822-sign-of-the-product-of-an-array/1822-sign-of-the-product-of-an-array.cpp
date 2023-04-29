class Solution {
public:
    int arraySign(vector<int>& nums) {
        int countNeg = 0, zero = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                countNeg++;
            }
            if(nums[i] == 0) return 0;
        }
        if(countNeg%2) return -1;
        else return 1;
    }
};