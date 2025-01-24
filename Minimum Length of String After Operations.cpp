class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        vector<vector<int>> freq(26);
        int count = 0;
        for(int i = 0; i < n; i++){
            char ch = s[i];
            freq[ch-'a'].push_back(i);
            if(freq[ch-'a'].size() == 3){
                count+=2;
                int mainIdx = freq[ch-'a'][1];
                freq[ch-'a'] = {mainIdx};
            }
        }
        return n - count;
    }
};
