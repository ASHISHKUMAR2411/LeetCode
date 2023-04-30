class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        vector<int> a(n2);
        stack<int> s;
        s.push(nums2[n2 - 1]);
        a[n2 - 1] = -1;
        for(int i = n2 - 2; i >= 0; i--){
            if(nums2[i+1] > nums2[i]){
                int temp = s.top();
                s.push(nums2[i]);
                a[i] = temp;
            }
            else{
                while(!s.empty()){
                    if(s.top() < nums2[i]) s.pop();
                    else break;
                }
                if(s.empty()){
                    a[i] = -1;
                    s.push(nums2[i]);
                }
                else{
                    int temp = s.top();
                    s.push(nums2[i]);
                    a[i] = temp;
                }
            }
        }
        map<int, int> mp;
        for(int i = 0; i < n2; i++){
            mp[nums2[i]] = a[i];
        }
        for(int i = 0; i < nums1.size(); i++){
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};