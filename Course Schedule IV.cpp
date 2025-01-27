class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& p, vector<vector<int>>& q) {
        vector<vector<int>> mat(n, vector<int> (n, 1e9));
        for(int i = 0; i < n; i++){
            mat[i][i] = 0;
        }
        for(auto &e : p){
            mat[e[0]][e[1]] = 1;
        }
        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                }
            }
        }
        vector<bool> res(q.size(), false);
        for(int i = 0; i < q.size(); i++){
            if(mat[q[i][0]][q[i][1]] != 1e9){
                res[i] = true;
            }
        }
        return res;
    }
};
