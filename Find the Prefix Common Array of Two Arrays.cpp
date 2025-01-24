class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> res(n, 0);
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(a[i]);
            st.insert(b[i]);
            int x = 2 * (i+1) - st.size();
            res[i] = x;
        }
        return res;
    }
};
