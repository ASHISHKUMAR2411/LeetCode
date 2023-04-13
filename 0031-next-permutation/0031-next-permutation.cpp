class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i1 = -1, i2 = -1, n = nums.size();
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                i1 = i;
                break;
            }
        }
        if(i1 == -1){
            sort(nums.begin(), nums.end());
            return;
        }
        i2 = -1;
        for(int i = i1 + 1; i < n; i++){
            if(nums[i1] < nums[i]){
                i2 = i;
            }
        }
        swap(nums[i1], nums[i2]);
        sort(nums.begin() + i1 + 1, nums.end());
    }
};