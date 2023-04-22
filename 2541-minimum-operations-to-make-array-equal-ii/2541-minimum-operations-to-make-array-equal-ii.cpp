class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k == 0){
            if(nums1 == nums2) return 0;
            else return -1;
            
        }
        int n = nums1.size();
        // vector<pair<int,int>> ans(n, 0);
        long long count = 0;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(nums1[i] > nums2[i]){
                if((nums1[i] - nums2[i])%k == 0)
                    count -= 1ll*((nums1[i] - nums2[i])/k);
                else return -1;
            }
            else if(nums1[i] < nums2[i]){
                if((nums2[i] - nums1[i])%k == 0){
                    count += 1ll*(nums2[i] - nums1[i])/k;
                    ans += 1ll*(nums2[i] - nums1[i])/k;
                }
                else{
                    return -1;
                }
            }
            // cout << count << " ";
        }
        if(count != 0) return -1;
        else return ans;
    }
};