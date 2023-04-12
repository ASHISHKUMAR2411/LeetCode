class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int ans = 0;
        int start = 0, end = 0;
        bool flag = true;
        int n = prices.size();
        for(int i = 1; i < n; i++){
            if(sum == 0){
                start = i - 1;
            }
            sum = prices[i] - prices[i-1];
            if(sum > 0){
                end = i;
            }
            else{
                sum = 0;
                if(end > start)
                ans += prices[end] - prices[start];
                if(i == n-1){
                    flag = false;
                }
            }
        }
        if(flag and end > start)
        ans += prices[end] - prices[start];
        return ans;
    }
};