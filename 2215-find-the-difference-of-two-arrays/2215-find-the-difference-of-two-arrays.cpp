class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        unordered_map<int,int> mp1, mp2;
        for(int i = 0; i < nums1.size(); i++){
            mp1[nums1[i]]++;
        }
        for(int i =0; i < nums2.size(); i++){
            mp2[nums2[i]]++;
        }
        set<int> a, b;
        for(int i = 0; i < nums1.size(); i++){
            if(mp2.find(nums1[i]) == mp2.end()){
                a.insert(nums1[i]);
            }
        }
        for(int i = 0; i < nums2.size(); i++){
            if(mp1.find(nums2[i]) == mp1.end()){
                b.insert(nums2[i]);
            }
        }
        vector<int> a1, b1;
        for(auto i : a){
            a1.push_back(i);
        }
        for(auto i : b){
            b1.push_back(i);
        }
        ans.push_back(a1);
        ans.push_back(b1);
        return ans;
    }
};