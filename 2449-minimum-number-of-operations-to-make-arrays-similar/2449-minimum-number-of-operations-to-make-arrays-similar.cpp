class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long count = 0, ans = 0;
        int n = target.size();
        vector<int> even_nums, odd_nums;
        vector<int> even_target, odd_target;
        for(int i =0; i < n ;i++){
            if(nums[i]%2) odd_nums.push_back(nums[i]);
            else even_nums.push_back(nums[i]);
            if(target[i]%2) odd_target.push_back(target[i]);
            else even_target.push_back(target[i]);
        }
        if(odd_nums.size() != odd_target.size()) return -1;
        if(even_nums.size() != even_target.size()) return -1;
        sort(odd_nums.begin(), odd_nums.end());
        sort(even_nums.begin(), even_nums.end());
        sort(even_target.begin(), even_target.end());
        sort(odd_target.begin(), odd_target.end());
        for(int i =0; i < even_nums.size(); i++){
            if(even_nums[i] > even_target[i]){
                count += (even_nums[i] - even_target[i])/2;
            }
            else{
                count += (even_target[i] - even_nums[i])/2;
            }
        }
        for(int i =0; i < odd_nums.size(); i++){
            if(odd_nums[i] > odd_target[i]){
                count += (odd_nums[i] - odd_target[i])/2;
            }
            else{
                count += (odd_target[i] - odd_nums[i])/2;
            }
        }
        if(count%2 == 0) return count/2;
        else return -1;
    }
};