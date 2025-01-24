typedef pair<int, pair<int, int>> P;
class Solution {
public:
    int m, n;
    bool isValid(int x, int y, int m, int n){
        return x < m && x >= 0 && y < n && y >= 0;
    }

    pair<int, int> findIdx(int x, int y, int dir){
        int x_, y_;
        if(dir == 1){
            x_ = x;
            y_ = y+1;
        }else if(dir == 2){
            x_ = x;
            y_ = y-1;
        }else if(dir == 3){
            x_ = x+1;
            y_ = y;
        }else{
            x_ = x-1;
            y_ = y;
        }
        return {x_, y_};
    }

    int dijkstra(unordered_map<string, vector<P>> &adj, int i, int j){
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(m, vector<int> (n, INT_MAX));
        // vector<vector<bool>> visited(m, vector<bool> (n, false));
        pq.push({0, {0,0}});
        result[0][0] = 0;
        while(!pq.empty()){
            int cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            string s = to_string(x)+" "+to_string(y);
            for(auto &v : adj[s]){
                int currCost = v.first;
                int x_ = v.second.first;
                int y_ = v.second.second;
                if(result[x_][y_] > cost+currCost){
                    result[x_][y_] = cost+currCost;
                    pq.push({cost+currCost, {x_, y_}});
                }
            }
        }   
        return result[m-1][n-1];
    }

    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        m = grid.size();
        n = grid[0].size();
        unordered_map<string, vector<P>> adj;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int d = grid[i][j];
                pair<int, int> def = findIdx(i, j, d); 
                string s = to_string(i)+" "+to_string(j);
                for(auto &v : dir){
                    int x_ = i+v[0];
                    int y_ = j+v[1];
                    if(isValid(x_, y_, m, n)){
                        if(x_ == def.first && y_ == def.second){
                            adj[s].push_back({0, {x_, y_}});
                        }else{
                            adj[s].push_back({1, {x_, y_}});
                        }
                    }
                }
            }
        }
        return dijkstra(adj, 0, 0);
    }
};
