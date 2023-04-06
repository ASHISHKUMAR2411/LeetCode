class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int d = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++ ){
            nums[i-d] = nums[i];
            if(nums[i] == 0){
                d++;
            }
        }
        n--;
        while(d){
            d--;
            nums[n--] = 0;
        }
    }
};