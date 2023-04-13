class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        stack<int> s1;
        int n1 = pu.size(), n2 = po.size();
        int i = 0, j=0;
        bool ans = true;
        while(i < n1 and j < n2){
            while(j < n2 and !(s1.empty()) and s1.top() == po[j]){
                s1.pop();
                j++;
            }
            if(i < n1){
                s1.push(pu[i]);
                i++;
            }
            while(j < n2 and !(s1.empty()) and s1.top() == po[j]){
                s1.pop();
                j++;
            }
            
        }
        while(j < n2 and (!s1.empty()) and s1.top() == po[j]){
            s1.pop();
            j++;
        }
        if(j < n2){
            return false;
        }
        if(s1.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};