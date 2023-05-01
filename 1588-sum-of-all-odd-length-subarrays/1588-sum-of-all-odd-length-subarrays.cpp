class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int total = 0;
        int n = arr.size();
        for(int i =0; i < n; i++){
            int o_l = i/2+1;
            int e_l = (i+1)/2;
            int e_r = (n-i)/2;
            int o_r = (n-i-1)/2 + 1;
            int k = o_r*o_l + e_l*e_r;
            total += k*arr[i];
        }
        return total;
    }
};