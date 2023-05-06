class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for(int i = 0; i < nums1.size(); i++){
            int index = nums2.rend() - lower_bound(nums2.rbegin(), nums2.rend(), nums1[i]);
            if(index > 0){
                // cout << index << endl;
                ans = max(ans, index - i - 1);
            }
            // cout << nums2[index] << " ";
        }
        return ans;
    }
};