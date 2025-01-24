class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();
        vector<int> map(26, 0);
        for(int i = 0; i < m; i++){
            vector<int> m(26, 0);
            for(auto &ch : words2[i]){
                m[ch-'a']++;
            }
            for(int i = 0; i < 26; i++){
                map[i] = max(map[i], m[i]);
            }
        }
        vector<string> res;
        for(int i = 0; i < n; i++){
            vector<int> map2(26, 0);
            for(auto &ch : words1[i]){
                map2[ch-'a']++;
            }
            bool flag = true;
            for(int i = 0; i < 26; i++){
                if(map2[i] < map[i]){
                    flag = false;
                    break;
                }
            }
            if(flag) res.push_back(words1[i]);
        }
        return res;
    }
};
