typedef long long ll;
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size();
        vector<int> idx(s.size(), 0);
        for(int i = 0; i < n; i++){
            int u = shifts[i][0];
            int v = shifts[i][1];
            int dir = shifts[i][2] == 0 ? -1 : 1;
            idx[u] += dir;
            if(v + 1 < s.size())
            idx[v+1] -= dir;
        }
        int val = idx[0];
        for(int i = 1; i < s.size(); i++){
            idx[i] += val;
            val = idx[i];
        }
        for(int i = 0; i < s.size(); i++){
            if(idx[i] == 0) continue;
            int dir = idx[i] < 0 ? -1 : 1;
            int shift = abs(idx[i]) % 26;
            while(shift--){
                s[i] += dir;
                if(dir == -1 && s[i] == 96){
                    s[i] = 122;
                }else if(dir == 1 && s[i] == 123){
                    s[i] = 97;
                }
            }  
        }
        return s;
    }
};
