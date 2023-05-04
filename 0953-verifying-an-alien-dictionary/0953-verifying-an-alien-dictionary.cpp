class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<int, int> mp;
        for(int i = 0; i < order.size(); i++){
            mp[order[i]] = i;
        }
        bool flag = true;
        for(int i = 1; i < words.size(); i++){
            int l = 0, r= 0; 
            while(r < words[i].size() && l < words[i-1].size() && words[i-1][l] == words[i][r]){
                l++; r++;
            }
            if(r != words[i].size() && l != words[i-1].size()){
                if(mp[words[i-1][l]] > mp[words[i][r]]){
                    flag = false;
                    break;
                }
            }
            else if(r == words[i].size() && l != words[i-1].size()){
                flag = false;
                break;
            }
        }
        return flag;
    }
};