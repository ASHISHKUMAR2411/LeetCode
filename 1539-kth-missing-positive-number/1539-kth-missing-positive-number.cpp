class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    }
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() , mid = 0;
        while(low<high){
            mid = (high + low)/2;
            if((arr[mid] - (mid+1)) < k){
                low = mid+1;
            }
            else high = mid;
        }
        return  k + low;
    }
};