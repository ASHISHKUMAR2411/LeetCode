class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        bool flag = false;
        for(int i = 1; i < c.size(); i++){
            int y = (c[i][0] - c[i-1][0]);
            if(y != 0){
                flag = true;
                break;
            }
        }
        if(!flag) return true;
        sort(c.begin(), c.end());
        float m = (float)(c[1][1] - c[0][1])/(c[1][0] - c[0][0]);
        // bool flag = true;
        cout << m << endl;
        for(int i = 1; i < c.size(); i++){
            // cout << (float)(c[i][1] - c[i-1][1]) << " " << (float)(c[i][0] - c[i-1][0]) << endl;
            float k = (float)(c[i][1] - c[i-1][1])/(float)(c[i][0] - c[i-1][0]);
            // cout << k << endl;
            if(k!=m) return false;
        }
        return true;
    }
};