class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
        set<string> s(wl.begin(), wl.end());
        queue<pair<string,int>> q;
        q.push({bw,1});
        int maxi = INT_MAX;
        while(!q.empty()){
            string f = q.front().first;
            int count = q.front().second;
            if(f == ew) maxi = min(maxi, count);
            q.pop();
            for(int i = 0; i < f.size(); i++){
                char ch = f[i];
                for(char c = 'a' ;  c <= 'z'; c++){
                    f[i] = c;
                    if(s.find(f) != s.end()){
                        s.erase(f);
                        q.push({f,count+1});
                    }
                }
                f[i] = ch;
            }
        }
        return maxi == INT_MAX ? 0 : maxi;
    }
};