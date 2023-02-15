class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n), right_max(n);
        left_max[0] = height[0];
        right_max[n-1] = height[n-1];
        int left_m = height[0], right_m = height[n-1];
        
        // for finding the left max array 
        for(int i = 1; i < n; i++){
            left_max[i] = max(left_m, height[i]);
            left_m = max(left_m, height[i]);
        }
        
        // for(int i = 0; i < n; i++){
        //     cout << left_max[i] << " ";
        // }
        // cout << endl;
        
        // for finding the right maximum array
        for(int i = n-2; i >= 0; i--){
            right_max[i] = max(right_m, height[i]);
            right_m = max(right_m, height[i]);
        }
        
        // for(int i = 0; i < n; i++){
        //     cout << right_max[i] << " ";
        // }
        // cout << endl;
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += min(left_max[i], right_max[i]) - height[i];
        }
        return sum;
        
    }
};