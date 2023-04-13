class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> se;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        do{
            se.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return se;
    }
};