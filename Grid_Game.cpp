typedef long long ll;
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int m = 2;
        int n = grid[0].size();
        vector<ll> pref1(n), pref2(n);
        pref1[0] = grid[0][0];
        pref2[0] = grid[1][0];
        for(int i = 1; i < n; i++){
            pref1[i] = pref1[i-1] + grid[0][i];
        }
        for(int i = 1; i < n; i++){
            pref2[i] = pref2[i-1] + grid[1][i];
        }
        ll val = LLONG_MAX, r1 = 0;
        for(int i = 0; i < n; i++){
            ll x = pref1[n-1] - pref1[i];
            ll y = 0;
            ll score = pref1[i] + pref2[n-1];
            if(i > 0){
                y = pref2[i-1];
                score -= pref2[i-1];
            }
            r1 = max(r1, score);
            val = min(val, max(x, y));
            // cout << x << y << " ";
        }
        return val;
    }
};
