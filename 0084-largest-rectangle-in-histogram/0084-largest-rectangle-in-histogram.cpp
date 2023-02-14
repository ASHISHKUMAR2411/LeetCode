class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> s1, s2;
        int n = h.size(), ans = 0;
        vector<int> left(n), right(n);
        // for left minimum
        s1.push(0);
        left[0] = -1;
        for(int i = 1; i < n; i++){
            while(!s1.empty()){
                if(h[s1.top()] > h[i]){
                    s1.pop();
                }
                else{
                    break;
                }
            }
            if(s1.empty()){
                left[i] = -1;
                s1.push(i);
            }
            else{
                left[i] = s1.top();
                s1.push(i);
            }
        }
        // for(int i = 0; i < n; i++){
        //     cout << left[i] << " ";
        // }
        // cout << endl;
        
        // for right smaller 
        s2.push(n-1);
        right[n-1] = -1;
        for(int i = n-2; i >= 0; i--){
            while(!s2.empty()){
                if(h[s2.top()] >= h[i]){
                    s2.pop();
                }
                else{
                    break;
                }
            }
            if(s2.empty()){
                right[i] = -1;
                s2.push(i);
            }
            else{
                right[i] = n - 1 - s2.top();
                s2.push(i);
            }
        }
        // for(int i = 0; i < n; i++){
        //     cout << right[i] << " ";
        // }
        // cout << endl;
        for(int i =0; i < n; i++){
            int count = abs(left[i] - i) + abs(right[i] - (n - 1 - i)) - 1;
            ans = max(ans, h[i]*count);
        }
        return ans;
        
    }
};