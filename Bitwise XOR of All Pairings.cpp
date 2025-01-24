typedef long long ll;
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size();
        ll m = nums2.size();
        unordered_map<ll, ll> mp1, mp2;
        for(auto &x : nums1){
            mp1[x]++;
        }
        for(auto &x : nums2){
            mp2[x]++;
        }
        int ans = 0;
        for(auto &x : mp1){
            ll ele = x.first;
            ll f = x.second;
            ll count = m * f;
            if(mp2[ele] != 0){
                count+= mp2[ele] + ((n-1) * mp2[ele]);
            }
            if(count % 2 != 0){
                ans ^= ele;
            }
        }
        for(auto &x : mp2){
            ll ele = x.first;
            ll f = x.second;
            if(mp1[ele] != 0) continue;
            ll count = n * f;
            if(count % 2 != 0){
                ans ^= ele;
            }
        }
        return ans;
    }
};
