class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> mp2;
        int grpNo = 0;
        mp[grpNo].push_back(sorted[n-1]);
        mp2[sorted[n-1]] = grpNo;
        for(int i = n-2; i >= 0; i--){
            while(i >= 0 && sorted[i+1] - sorted[i] <= limit){
                mp[grpNo].push_back(sorted[i]);
                mp2[sorted[i]] = grpNo;
                i--;
            }
            if(i < 0) break;
            grpNo++;
            mp[grpNo].push_back(sorted[i]);
            mp2[sorted[i]] = grpNo;
        }
        vector<int> res(n, -1);
        for(int i = 0; i < n; i++){
            int grpno = mp2[nums[i]];
            if(mp[grpno].size() == 0)break;
            res[i] = mp[grpno].back();
            mp[grpno].pop_back();
        }
        return res;
    }
};
