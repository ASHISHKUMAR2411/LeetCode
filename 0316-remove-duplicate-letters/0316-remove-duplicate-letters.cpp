class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        int n = s.size();
        vector<int> freq(26, 0);
        vector<bool> visited(26, false);
        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++;
        }
        for(int i =0; i < n; i++){
            freq[s[i] - 'a']--;
            while( !(st.empty()) and (s[i] - 'a') < ((st.top()) - 'a') and freq[st.top() - 'a'] > 0 and !visited[s[i] - 'a']){
                visited[(st.top()) - 'a'] = false;
                st.pop();
                
            }
            if(!visited[s[i] - 'a'])
                st.push(s[i]);
            visited[s[i] - 'a'] = true;
        }
        string so; 
        while(!(st.empty())){
            so.push_back(st.top());
            st.pop();
        }
        reverse(so.begin(), so.end());
        return so;
        
    }
};