class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l = 0, r= 0;
        string ans = "";
        int count = 0;
        while(l < word1.size() and r < word2.size()){
            if(count%2 == 0){
                ans += word1[l];
                l++;
            }
            else{
                ans += word2[r];
                r++;
            }
            count++;
        }
        while(l < word1.size()){
            ans += word1[l];
            l++;
        }
        while(r < word2.size()){
            ans += word2[r];
            r++;
        }
        return ans;
    }
};