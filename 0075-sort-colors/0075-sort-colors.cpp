class Solution {
public:
    void sortColors(vector<int>& nums) {
        int os = 0, zs = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                zs++;
            }
            else if(nums[i] == 1){
                os++;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(zs > 0){
                nums[i] = 0;
                zs--;
            }
            else if(os > 0){
                nums[i] = 1;
                os--;
            }
            else{
                nums[i] = 2;
            }
        }
        
    }
};