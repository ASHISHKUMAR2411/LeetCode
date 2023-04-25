class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        int n = b.size();
        if(m*1ll*k > n) return -1;
        int l = 1, r = *max_element(b.begin(), b.end());
        int mini = INT_MAX;
        while(l <= r){
            int mid = (l + r)/2;
            int flower = 0, count = 0;
            int p2 = 0;
            while(p2 < b.size()){
                if(b[p2] <= mid){
                    count++;
                    if(count == k){
                        count = 0;
                        flower++;
                    }
                    
                }
                else{
                    if(count >= k){
                        flower++;
                    }
                    count = 0;
                }
                p2++;
            }
            if(flower >= m){
                mini = min(mini, mid);
                r = mid -1;
            }
            else {
                l = mid + 1;
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};