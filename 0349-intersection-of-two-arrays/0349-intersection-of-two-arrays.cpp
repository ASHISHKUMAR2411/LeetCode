class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int l = 0, r = 0;
        int n = nums1.size(), m = nums2.size();
        while(l < n and r < m){
            if(nums1[l] == nums2[r]){
                ans.push_back(nums1[l]);
                int x = nums1[l];
                int index = l+ 1;
                while(l < n and nums1[l] == x){
                    l++;
                }
                if(l >= index){
                    l--;
                }
                index = r + 1;
                while(r < m and nums2[r] == x){
                    r++;
                }
                if(r >= index){
                    r--;
                }
                l++;
                r++;
            }
            else if(nums1[l] > nums2[r]){
                r++;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};