class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Brute Force Complexity : O(n) time, O(n/3) space
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        int n = 0;
        for(auto i : mp){
            if(i.second != 3){
                n = i.first ;
                break;
            }
        }
        return n;
    }
};