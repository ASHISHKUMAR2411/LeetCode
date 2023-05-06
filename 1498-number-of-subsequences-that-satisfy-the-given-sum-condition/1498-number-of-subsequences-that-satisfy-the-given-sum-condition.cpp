class Solution {
public:
    int power(int a, int b, int mod){
        int res = 1;
        while(b){
            if(b&1) res = (res%mod*1ll*a%mod)%mod;
            a = (a%mod*1ll*a%mod)%mod;
            b >>= 1;
        }
        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
        int count = 0;
        int mod = 1e9+7;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int ind = upper_bound(nums.begin() , nums.end(), target - nums[i]) - nums.begin() - i;
            // cout << ind << " ";
            if(ind > 0){
                count = (count%mod + 1%mod)%mod;
                if(ind - 2 >= 0){
                    count = (count%mod + (power(2,ind-1,mod) - 1 + mod)%mod)%mod;
                }
            }
        }
        return count;
    }
};