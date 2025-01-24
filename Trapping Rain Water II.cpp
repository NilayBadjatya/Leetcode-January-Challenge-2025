typedef pair<int, pair<int, int>> P;
class Solution {
public:

    bool isValid(int x, int y, int m, int n){
        return x >=0 && x < m && y >= 0 && y < n;
    }

    int trapRainWater(vector<vector<int>>& h) {
        int m = h.size();
        int n = h[0].size();
        int count = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        for(int i = 0; i < m; i++){
            pq.push({h[i][0], {i,0}});
            pq.push({h[i][n-1], {i, n-1}});
            visited[i][0] = true;
            visited[i][n-1] = true;
        }
        for(int j = 0; j < n; j++){
            pq.push({h[0][j], {0,j}});
            pq.push({h[m-1][j], {m-1, j}});
            visited[0][j] = true;
            visited[m-1][j] = true;
        }
        while(!pq.empty()){
            int hi = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for(auto &v : dir){
                int x_ = x + v[0];
                int y_ = y + v[1];
                if(isValid(x_,y_,m,n) && !visited[x_][y_]){
                    count += max(hi - h[x_][y_], 0);
                    visited[x_][y_] = true;
                    pq.push({max(hi, h[x_][y_]), {x_, y_}});
                }
            }
        }
        return count;
    }
};
