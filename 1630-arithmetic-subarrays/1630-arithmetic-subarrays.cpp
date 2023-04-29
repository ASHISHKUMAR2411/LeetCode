class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size(), n = nums.size();
        vector<bool> ans(m, false);
        for(int i = 0; i < m; i++){
            int li = l[i], ri = r[i];
            int si = ri-li+1;
            vector<int> k(si, 0);
            for(int j = 0; j < si; j++){
                k[j] = nums[j+li];
            }
            sort(k.begin(), k.end());
            // for(int j = 0; j < si; j++){
            //     cout << k[j] << " ";
            // }
            // cout << endl;
            int diff = k[1] - k[0];
            int flag = 1;
            for(int o = 1; o < si; o++){
                if((k[o] - k[o-1]) != diff){
                    flag = 0;
                    break;
                }
            }
            if(flag) ans[i] = true;
        }
        return ans;
    }
};