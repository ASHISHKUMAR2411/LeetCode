//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    int wordLadderLength(string sw, string tw, vector<string>& wl) {
        // Code here
        set<string> s(wl.begin(), wl.end());
        queue<pair<string, int>> q;
        q.push({sw, 1});
        int maxi = 0;
        while(!q.empty()){
            string f = q.front().first;
            int count = q.front().second;
            if(f == tw){
                maxi = max(maxi, count);
            }
            q.pop();
            for(int i = 0; i < f.size(); i++){
                char ch = f[i];
                for(char c = 'a'; c <= 'z'; c++){
                    if(c != f[i]){
                        f[i] = c;
                        // cout << f << endl;
                        if(s.find(f) != s.end()){
                            q.push({f, count+1});
                            s.erase(f);
                        }
                    }
                }
                f[i] = ch;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends