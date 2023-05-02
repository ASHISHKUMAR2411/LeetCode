class Solution {
public:
    int countHomogenous(string s) {
        int count = 0, mod = 1e9+7;
        int l =0;
        unordered_map<char,int> mp;
        for(int i= 0; i < s.size(); i++){
            mp[s[i]]++;
            if(mp.size() == 1){
                count= (count%mod + mp[s[i]]%mod)%mod;
            }
            if(mp.size() > 1){
                for(auto k:mp){
                    if(k.first != s[i]){
                        mp.erase(k.first);
                        break;
                    }
                }
                if(mp.size() == 1) count = (count%mod + 1%mod)%mod;
            }
        }
        return count%mod;
    }
};