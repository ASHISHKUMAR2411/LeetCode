class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ni) {
        for(int i = 0; i < in.size(); i++){
            if((ni[0] >= in[i][0] and ni[0] <= in[i][1]) || (ni[1] >= in[i][0] and ni[1] <= in[i][1]) || (in[i][0] >= ni[0] and in[i][1] <= ni[1])){
                in[i][0] = min(ni[0], in[i][0]);
                in[i][1] = max(ni[1], in[i][1]);
            }
            else if(ni[0] < in[i][0] and ni[1] < in[i][0]){
                vector<int> v{ni[0], ni[1]};
                in.insert(in.begin() + i, v);
                break;
            }
        }
        if(in.size() == 0){
            in.push_back(ni);
        }
        else if(in[in.size() - 1][1] < ni[0]){
            in.push_back(ni);
        }
        vector<vector<int>> ans;
        ans.push_back(in[0]);
        for(int i = 1; i < in.size(); i++){
            if(in[i-1][1] >= in[i][0]){
                ans[ans.size() - 1][0] = min(ans[ans.size() - 1][0], in[i][0]);
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], in[i][1]);
            }
            else{
                ans.push_back(in[i]);
            }
        }
        return ans;
    }
};