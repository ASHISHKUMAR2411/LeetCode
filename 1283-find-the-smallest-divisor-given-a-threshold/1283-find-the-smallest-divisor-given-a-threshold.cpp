class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        int mini = INT_MAX;
        while(l <= r){
            int mid = (l + r)/2;
            int count = 0;
            for(int i = 0; i < nums.size(); i++){
                count += ceil((double)nums[i]/mid);
            }
            if(count <= t){
                mini = min(mini, mid);
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return mini;
    }
};