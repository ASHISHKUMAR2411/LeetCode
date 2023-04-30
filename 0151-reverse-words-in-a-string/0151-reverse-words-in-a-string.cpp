class Solution {
public:
    void removeSpaces(string &s){
        int n = s.size();
        int i = 0, j = -1;
        bool spaceFound = false;
        while (++j < n && s[j] == ' ');
        while (j < n)
        {
            // if current characters is non-space
            if (s[j] != ' ')
            {
                    s[i++] = s[j++];
                    spaceFound = false;
            }
            else if (s[j++] == ' ')
            {
                if (!spaceFound)
                {
                    s[i++] = ' ';
                    spaceFound = true;
                }
            }
        }
        while(s[s.size() - 1] == ' '){
            s.erase(s.size() - 1, 1);
        }
    }
    string reverseWords(string s) {
        s+=" ";
        string ans,t;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(t!="")
                ans=t+" "+ans;
                t="";
            }else{
                t+=s[i];
            }
        }
        return ans.substr(0,ans.length()-1);
    }
};