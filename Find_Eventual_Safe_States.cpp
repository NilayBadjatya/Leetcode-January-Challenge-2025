class Solution {
public:

    bool dfs(vector<vector<int>>& graph, int node, vector<bool> &visited, vector<bool> &inRecursion){
        visited[node] = true;
        inRecursion[node] = true;
        for(auto &v : graph[node]){
            if(visited[v] && inRecursion[v]){
                return false;
            }
            if(inRecursion[v]){
                return false;
            }
            if(!visited[v] && !dfs(graph, v, visited, inRecursion)){
                return false;
            }
        }
        inRecursion[node] = false;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(graph, i, visited, inRecursion);
            }
        }
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(inRecursion[i] == false){
                res.push_back(i);
            }
        }
        return res;
    }
};
