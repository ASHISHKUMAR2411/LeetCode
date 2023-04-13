class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int i = 0, j = 0, k= 0;
        while(nums[i] < 0) i++;
        while(nums[j] >= 0) j++;
        bool flag = true;
        while(i < n and j < n){
            if(flag){
                ans[k++] = nums[i++];
                while(i < n and nums[i] < 0)i++;
            }
            else{
                ans[k++] = nums[j++];
                while(j < n and nums[j] >= 0) j++;
            }
            flag = !flag;
        }
        while(i < n){
            ans[k++] = nums[i++];
            while(i < n and nums[i] < 0)i++;
        }
        while(j < n){
            ans[k++] = nums[j++];
            while(j < n and nums[j] >= 0) j++;
        }
        return ans;
    }
};