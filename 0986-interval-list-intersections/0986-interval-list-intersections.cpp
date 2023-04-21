class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        set<vector<int>> ans;
        int st = 0, en = 0;
        for(int i =0; i < f.size(); i++){
            for(int j = 0; j < s.size(); j++){
                st = max(s[j][0], f[i][0]);
                en = min(s[j][1], f[i][1]);
                if(st >= f[i][0] and en <= f[i][1] and en >= st){
                    vector<int> a{st, en};
                    ans.insert(a);
                }
            }
        }
        vector<vector<int>> res;
        for(auto i : ans){
            res.push_back(i);
        }
        return res;
    }
};