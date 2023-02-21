class Solution {
public:
    void solve(int l, int r, int &ans, vector<int> &nums){
        if(l > r) return;
        int mid = (l + r)/2;
        int flag = false;
        if(mid > 0 and nums[mid] == nums[mid-1]){
            flag = true;
        }
        if(mid < (nums.size() - 1) and nums[mid] == nums[mid + 1]){
            flag = true;
        }
        if(flag){
            solve(mid + 1, r, ans, nums);
            solve(l, mid -1, ans, nums);
        }
        else{
            ans = nums[mid];
        }
    }
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, ans = -1;
            solve(l,r,ans,nums);
        return ans;
    }
};