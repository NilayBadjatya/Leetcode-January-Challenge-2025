class Solution {
public:
    bool isPrefixAndSuffix(string& pat, string& txt) {
        if(txt.substr(0, pat.size()) != pat){
            return false;
        }
        int nextRes = txt.find(pat, (txt.size() - pat.size()));
        if (nextRes == -1) {
            return false;
        }
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (words[i] == words[j] ||
                    isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};
