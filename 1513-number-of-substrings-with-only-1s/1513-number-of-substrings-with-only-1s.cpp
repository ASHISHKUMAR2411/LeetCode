class Solution {
public:
    int numSub(string s) {
        int mod = 1e9+7, count = 0, res = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                count++;
            }
            else{
                count = 0;
            }
            res = (res%mod + count%mod)%mod; 
        }
        return res;
    }
};