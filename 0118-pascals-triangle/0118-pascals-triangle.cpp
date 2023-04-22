class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        int c = 1;
        for(int i = 1; i <= n; i++ ){
            int c = 1;
            vector<int> a;
            for(int j = 1; j <= i; j++){
                a.push_back(c);
                c = c * (i - j)/j;
            }
            ans.push_back(a);
        }
        return ans;
    }
};