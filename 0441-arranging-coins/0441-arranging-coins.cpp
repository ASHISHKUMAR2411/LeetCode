class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1, r = sqrt(2*1ll*n);
        while(l<r){
            int mid = l + (r-l)/2;
            int cost = abs((mid *1ll*(mid +1))/2 - n);
            if(cost > mid){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return l;
        
    }
};