class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int s = m*n;
        vector<int> cntCol(n, 0);
        vector<int> cntRow(m, 0);
        vector<pair<int, int>> a(s+1);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int x = mat[i][j];
                a[x] = {i, j};
            }
        }
        for(int i = 0; i < s; i++){
            int row = a[arr[i]].first;
            int col = a[arr[i]].second;
            cntRow[row]++;
            if(cntRow[row] == n){
                return i;
            }
            cntCol[col]++;
            if(cntCol[col] == m){
                return i;
            }
        }
        return -1;
    }
};
