class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        if(h == 1) return piles[0];
        sort(piles.begin(), piles.end());
        int n = piles.size();
        if(n == 1){
            // cout << (n/ )piles[0]/h;
            return ceil((double)piles[0]/h);
         }
        int l = 1, r = piles[n-1];
        int mini = INT_MAX;
        while(l <= r){
            int mid = (l + r)/2;
            long long total = 0;
            for(int i = 0; i < n; i++){
                total += ceil((double)(piles[i])/mid);
            }
            if(total <= h){
                mini = min(mini, mid);
                r = mid -1;
            }
            else
                l = mid + 1;
        }
        return mini;
    }
};