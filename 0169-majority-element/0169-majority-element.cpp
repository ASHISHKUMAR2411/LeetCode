class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = -1, maj_ind = 0, count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[maj_ind]){
                count++;
            }
            else{
                count--;
            }
            if(count == 0){
                maj_ind = i;
                count = 1;
            }
        }
        count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == nums[maj_ind]){
                count++;
            }
        }
        if(count>(nums.size())/2){
            return nums[maj_ind];
        }
        else{
            return -1;
        }
    }
};