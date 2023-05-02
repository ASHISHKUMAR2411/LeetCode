class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    if((int)(mat.size()) * ((int)(mat[0].size())) == r*c){
        int m = mat.size() , n = mat[0].size();
        vector<vector<int>> p;
        int mi = 0;
        for(int i = 0; i< r ; i++){
            vector<int> r;
            for(int j = 0; j < c; j++){
                r.push_back(mat[mi/n][mi%n]);
                mi++;
            }
            p.push_back(r);
        }
        return p;
    }
        else
            return mat;
    }
};