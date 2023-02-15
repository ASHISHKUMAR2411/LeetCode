class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxi = 0;
        vector<vector<int>> v(words.size(), vector<int>(26, 0));
        for(int i =0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                v[i][words[i][j] - 'a'] = 1;
            }
        }
        // for(int i =0; i < words.size(); i++){
        //     for(int j = 0; j < 26; j++){
        //         cout << v[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int i = 0; i < words.size(); i++){
            int length = words[i].size();
            for(int j = i+1; j < words.size(); j++){
                bool flag = true;
                for(int k = 0; k < 26; k++){
                //     cout << words[i] << " " << words[j] << endl;
                //     cout << words[i][k]  << " " << words[j][k] << endl;
                    if((v[i][k]&v[j][k])){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    int y = length * words[j].size();
                    maxi = max(maxi, y);
                }
            }
        }
        return maxi;
    }
};