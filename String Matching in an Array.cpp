class Solution {
public:
    // KMP Algorithm
    vector<int> findLPS(string &pat, int n){
        int len = 0;
        int i = 1;
        vector<int> lps(n, 0);
        while(i < n){
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0){
                    len = lps[len-1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    bool isSubstring(string &pat, string &txt){
        int n = pat.size();
        int m = txt.size();
        vector<int> lps = findLPS(pat, n);
        int i = 0, j = 0;
        while(i < m){
            if(txt[i] == pat[j]){
                i++;
                j++;
            }
            if(j == n){
                return true;
            }else if(txt[i] != pat[j]){
                if(j != 0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> res;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(isSubstring(words[i], words[j])){
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};
