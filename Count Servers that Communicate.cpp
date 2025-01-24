class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
    int x_p = find(x);
    int y_p = find(y);
        if(x_p != y_p){
            if(rank[x_p] > rank[y_p]){
                parent[y_p] = x_p;
            }else if(rank[y_p] > rank[x_p]){
                parent[x_p] = y_p;
            }else{
                parent[x_p] = y_p;
                rank[y_p]++;
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int nodes = 0, o = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    nodes++;
                    string s = to_string(i) + " " + to_string(j);
                    mp[s] = o++;
                }
            }
        }
        parent.resize(n, -1);
        rank.resize(n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    
                }
            }
        }
        
    }
};
