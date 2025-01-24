class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(k == n) return true;
        unordered_map<char, int> mp;
        for(auto &ch : s){
            mp[ch]++;
        }
        int c = 0, c2 = 0;
        for(auto &x : mp){
            int f = x.second;
            if(f % 2 == 0){
                c += f;
            }else{
                c2++;
                c += f - 1;
            }
        }
        cout << c << " " << c2;
        if(c2 > k) return false;
        if(c + c2 >= k || c2 == k){
            return true;
        }
        return false;
    }
};
