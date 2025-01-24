class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> st(s.begin(), s.end());
        int n = s.size(), ans = 0;
        for(auto &ch : st){
            int last = -1, first = -1;
            for(int i = n - 1; i >= 0; i--){
                if(s[i] == ch){
                    last = i;
                    break;
                }
            }
            for(int i = 0; i < n; i++){
                if(s[i] == ch){
                    first = i;
                    break;
                }
            }
            if(last == first) continue;
            unordered_set<char> st2;
            for(int k = first + 1; k < last; k++){
                st2.insert(s[k]);
            }
            ans += st2.size();
        }
        return ans;
    }
};
