class Solution {
public:
    bool check(int val, vector<int> &w, int d){
        int count = 1, sum = 0;
        for(int i = 0; i < w.size(); i++){
            if(sum + w[i] <= val){
                sum += w[i];
            }
            else{
                count++;
                sum = w[i];
            }
        }
        return count <= d;
    }
    int shipWithinDays(vector<int>& w, int d) {
        int l = *max_element(w.begin(), w.end());
        int r = accumulate(w.begin(), w.end(), 0);
        int ans = l;
        while(l <= r){
            int mid = (l + r)/2;
            if(check(mid, w, d)){
                r = mid - 1;
                ans = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};