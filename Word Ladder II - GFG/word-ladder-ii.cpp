//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string bw, string ew, vector<string>& wl) {
        // code here
        vector<vector<string>> ans;
        set<string> s(wl.begin(), wl.end());
        vector<string> a;
        a.push_back(bw);
        queue<vector<string>> q;
        q.push(a);
        while(!q.empty()){
            bool flag = false;
            int size = q.size();
            unordered_set<string> t;
            for(int i = 0; i < size; i++){
                vector<string> temp = q.front();
                q.pop();
                string f = temp[temp.size() - 1];
                for(int i = 0; i < f.size(); i++){
                    char ch = f[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        f[i] = c;
                        if(s.find(f) != s.end()){
                            t.insert(f);
                            temp.push_back(f);
                            q.push(temp);
                            temp.pop_back();
                        }
                    }
                    f[i] = ch;
                }
            }
            for(auto i : t){
                if(i == ew){
                    flag = true;
                    break;
                }
                if(s.find(i) != s.end()){
                    s.erase(i);
                }
            }
            if(flag) break;
        }
        while(!q.empty()){
            vector<string> temp = q.front();
            q.pop();
            if(temp[temp.size() - 1] == ew){
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

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
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends