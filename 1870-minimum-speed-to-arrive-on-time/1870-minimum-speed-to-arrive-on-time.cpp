class Solution {
public:
    bool check(int mid, vector<int> &dist, double hour){
        double h = 0.00;
        for(int i = 0; i < dist.size(); i++){
            if(i == dist.size() - 1){
                h += (double)(dist[i])/(double)mid;
            }
            else{
                h += ceil((double)(dist[i])/(double)(mid));
            }
        }
        return h <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 10000000, ans = -1;
        while(l <= r){
            int mid = (l + r)/2;
            if(check(mid, dist, hour)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};