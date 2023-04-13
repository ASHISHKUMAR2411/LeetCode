class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> se;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        do{
            vector<int> v;
            for(int i = 0; i < n; i++){
                v.push_back(nums[i]);
            }
            se.insert(v);
        }while(next_permutation(nums.begin(), nums.end()));
        vector<vector<int>> ans;
        for(auto i : se){
            vector<int> v;
            for(int j = 0; j < i.size(); j++){
                v.push_back(i[j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};