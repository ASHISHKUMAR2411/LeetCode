class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        stack<char> st, t;
        if(typed.size() < name.size()) return false;
        for(int i = 0; i < typed.size(); i++){
            st.push(typed[i]);
        }
        for(int i = name.size() - 1; i > 0; i--){
            // cout << name[i] << " " << name[i-1] << " top " << st.top() << endl;
            if(name[i] != name[i-1]){
                if(st.top() == name[i])
                while(!(st.empty()) and st.top() == name[i]) st.pop();
                else return false;
            }
            else if(!st.empty() and st.top() == name[i]){
                st.pop();
            }
            else{
                return false;
            }
        }
        if(st.empty()) return false;
        while(!(st.empty()) and name[0] == st.top()){
            st.pop();
        }
        if(st.empty()) return true;
        else return false;
    }
    
};