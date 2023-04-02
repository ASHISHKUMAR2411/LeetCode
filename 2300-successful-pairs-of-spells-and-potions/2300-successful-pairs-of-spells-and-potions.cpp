class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long su) {
        sort(p.begin(), p.end());
        vector<int> ans;
        int n = s.size(), m = p.size();
        for(int i =0; i < n; i++){
            long long j = ceil((long double)(su)/(long double)(s[i]));
            // cout << j << endl;
            auto k = lower_bound(p.begin(), p.end(), j);
            int pos = 0;
            if(k == p.end()){
                pos = m;
            }
            else{
                pos = k - p.begin();
            }
            cout << pos << endl;
            ans.push_back(m - pos);
        }
        return ans;
    }
};