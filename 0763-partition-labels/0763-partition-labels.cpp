class Solution {
public:
    vector<int> partitionLabels(string s) {
            //merging the intervals together 
        map<char, pair<int, int>> mp;
        for(int i = 0; i < s.length(); i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = {i+1, i+1};
            }
            else{
                mp[s[i]].second = max(mp[s[i]].second, i + 1);
            }
        }
        vector<vector<int>> v;
        for(auto i : mp){
            vector<int> vi = {i.second.first, i.second.second};
            v.push_back(vi);
        }
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        ans.push_back(v[0]);
        for(int i = 1; i < v.size(); i++){
            if(v[i][0] <= ans[ans.size() - 1][1]){
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], v[i][1]);
            }
            else{
                ans.push_back(v[i]);
            }
        }
        vector<int> answer;
        for(int i =0; i < ans.size(); i++){
            answer.push_back(ans[i][1] - ans[i][0] + 1);
        }
        return answer;
    }
};