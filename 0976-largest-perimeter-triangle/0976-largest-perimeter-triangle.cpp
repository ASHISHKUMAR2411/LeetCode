class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = n -1;
        while(i >= 2){
            int a = nums[i], b = nums[i-1], c = nums[i-2];
            if((a+b) > c and (b+c) > a and (c + a) > b and abs(c - a) < b and abs(c-b) < a and abs(a - b) < c){
                return a+b+c;
            }
            i--;
        }
        return 0;
    }
};