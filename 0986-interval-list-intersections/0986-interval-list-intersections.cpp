class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
//         two pointer using interval aage jana 
        int i = 0, j= 0;
        vector<vector<int>> ans;
        while(i < f.size() and j < s.size()){
            int st = max(f[i][0], s[j][0]);
            int en = min(f[i][1], s[j][1]);
            if(st <= en){
                ans.push_back({st,en});
            }
            if(f[i][1] < s[j][1]) i++;
            else j++;
        }
        return ans;
    }
};