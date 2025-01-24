typedef pair<int, int> P;
class Solution {
public:

    bool isValid(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<P> q;
        vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    // grid[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(auto &v : dir){
                    int x = i + v[0];
                    int y = j + v[1];
                    if(isValid(x, y, m, n) && grid[x][y] == 0){
                        grid[x][y] = grid[i][j] + 1;
                        q.push({x,y});
                    }
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 1){
                    grid[i][j]--;
                }else if(grid[i][j] == 1){
                    grid[i][j] = 0;
                }
            }
        }
        return grid;
    }
};
