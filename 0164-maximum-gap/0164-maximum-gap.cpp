class Solution {
public:
    int maximumGap(vector<int>& nums) {
        set<int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        int maxi = 0, prev = *(s.begin());
        for(auto i : s){
            maxi = max(maxi, i - prev);
            prev = i;
        }
        return maxi;
    }
};