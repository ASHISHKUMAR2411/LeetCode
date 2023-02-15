class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> a1(26, 0), b1(26, 0);
        for(int i =0; i < s.size(); i++){
            a1[s[i] - 'a']++;
            b1[t[i] - 'a']++;
        }
        b1[t[s.size()] - 'a']++;
        int c = 0;
        for(int i = 0; i < 26;i++){
            if(a1[i] != b1[i]){
                c = i;
                break;
            }
        }
        return 'a' + c;
    }
};