class Solution {
public:
    int findPoisonedDuration(vector<int>& ts, int d) {
        int total = d;
        for(int i = 1; i < ts.size(); i++){
            int s = ts[i-1], e = min(ts[i-1] + d, ts[i]);
            total += e - s;
        }
        return total;
    }
};