class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> s_;
        map<string, int> mp;
        if(s.size() <= 10) return s_;
        string s1 = "";
        for(int i = 0; i < 10; i++){
            s1 += s[i];
        }
        // cout << s1 << endl;
        mp[s1]++;
        // cout << mp[s1] << endl;
        for(int i = 10; i < s.size(); i++){
            s1 = s1.substr(1, s1.size() - 1) + s[i];
            // cout << s1 << endl;
            mp[s1]++;
            // cout << mp[s1] << endl;
        }
        for(auto i : mp){
            if(i.second >= 2){
                s_.push_back(i.first);
            }
        }
        return s_;
    }
};