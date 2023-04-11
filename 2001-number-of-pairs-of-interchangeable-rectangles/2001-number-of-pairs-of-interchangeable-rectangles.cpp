class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& r) {
        long long ans = 0; 
        map<double, int> mp;
        int n = r.size();
        for(int i = 0; i < n; i++){
            double d = (double)(r[i][0])/(r[i][1]);
            mp[d]++;
        }
        for(auto i : mp){
            int s = i.second;
            ans += (s *1ll* (s - 1))/2;
        }
        return ans;
    }
};