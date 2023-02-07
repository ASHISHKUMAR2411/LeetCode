class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans= nums, ans1 = nums, a(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            ans[i] *= ans[i - 1];
        }
        for(int i = nums.size() - 2; i >= 0; i--){
            ans1[i] *= ans1[i + 1];
        }
        for(int i = 0; i < nums.size(); i++){
            int pro = 1;
            if(i == 0)
                pro = ans1[1];
            else if( i == nums.size() - 1)
                pro = ans[i - 1];
            else{
                pro = pro * ans[i-1] * ans1[i+1];
            }
            a[i] = pro;
        }
        return a;
        
        
    }
};