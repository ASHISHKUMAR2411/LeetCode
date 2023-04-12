class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;
        for(int i = 0; i < n; i++){
            string s;;
            if(path[i] != '/'){
                while(i < n  and path[i] != '/'){
                    s.push_back(path[i]);
                    i++;
                }
            }
            if(s.size()){
                if(s == ".."){
                    if(!(st.empty()))
                    st.pop();
                }
                else if(s != "."){
                    st.push(s);
                }
            }
        }
        stack<string> sj;
        while(!(st.empty())){
            // cout << st.top() << " ";
            sj.push(st.top());
            st.pop();
        }
        // cout << endl;
        string ans = "/";
        while(!(sj.empty())){
            ans += sj.top() + "/";
            sj.pop();
        }
        if(ans.size() != 1){
            ans.erase(ans.size() - 1, 1);
        }
        return ans;
    }
};