class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<int> maxh;
        map<int,int> mp;
        int n = nums.size();
        for(int i = 0; i < k; i++){
            mp[nums[i]]++;
            maxh.push(nums[i]);
        }
        ans.push_back(maxh.top());
        for(int i = k; i < n; i++){
            mp[nums[i]]++;
            maxh.push(nums[i]);
            mp[nums[i-k]]--;
            while(mp[maxh.top()] == 0 and !(maxh.empty())){
                maxh.pop();
            }
            ans.push_back(maxh.top());
        }
        return ans;
        
    }
};