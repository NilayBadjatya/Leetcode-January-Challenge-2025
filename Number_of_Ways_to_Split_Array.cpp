typedef long long ll;
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<ll> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        int count = 0;
        for(int i = 0; i < n-1; i++){
            if(prefix[i] >= prefix[n-1] - prefix[i]){
                count++;
            }
        }
        return count;
    }
};
