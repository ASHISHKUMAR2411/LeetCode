class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Efficient Solution 
        int ones = 0, two = 0;
        for(auto i : nums){
            ones = (ones ^ i) & (~two);
            two = (two ^ i) & (~ones);
        }
        return ones;
        // Brute Force Complexity : O(n) time, O(n/3) space
        // map<int, int> mp;
        // for(int i = 0; i < nums.size(); i++){
        //     mp[nums[i]]++;
        // }
        // int n = 0;
        // for(auto i : mp){
        //     if(i.second != 3){
        //         n = i.first ;
        //         break;
        //     }
        // }
        // return n;
    }
};