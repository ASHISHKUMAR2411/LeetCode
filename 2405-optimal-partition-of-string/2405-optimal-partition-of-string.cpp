class Solution {
public:
    int partitionString(string s) {
        int count = 0;
        set<char> st;
        int prev = 0;
        for(int i = 0; i < s.size(); i++){
            st.insert(s[i]);
            if(st.size() != (i - prev + 1)){
                count++;
                for(auto i : st){
                    cout << i << " ";
                }
                cout << endl;
                st.clear();
                st.insert(s[i]);
                prev = i;
            }
        }
        if(st.size()){
            count++;
        }
        return count;
        
    }
};