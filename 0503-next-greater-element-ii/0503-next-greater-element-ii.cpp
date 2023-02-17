class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n); 
        stack<int> s;
        s.push(nums[n-1]);
        a[n-1] = INT_MIN;
        // first finding the greater number right 
        for(int i = n-2; i >=0; i--){
            if(nums[i+1] > nums[i]){
                s.push(nums[i]);
                a[i] = nums[i+1];
            }
            else{
                while(!s.empty()){
                    if(s.top() > nums[i]){
                        break;
                    }
                    else{
                        s.pop();
                    }
                }
                if(s.empty()){
                    a[i] = INT_MIN;
                    s.push(nums[i]);
                }
                else{
                    a[i] = s.top();
                    s.push(nums[i]);
                }
            }
        }
        // then for those which has not found their greater element on the right, find their greater element on the left. As the stack is gone till 0 so it should store 
        for(int i = n-1; i>=0; i--){
            if(a[i] == INT_MIN){
                while(!s.empty()){
                    if(s.top() > nums[i]){
                        break;
                    }
                    else{
                        s.pop();
                    }
                }
                if(s.empty()){
                    a[i] = -1;
                    s.push(nums[i]);
                }
                else{
                    a[i] = s.top();
                    s.push(nums[i]);
                }
            }
        }
        return a;
    }
};