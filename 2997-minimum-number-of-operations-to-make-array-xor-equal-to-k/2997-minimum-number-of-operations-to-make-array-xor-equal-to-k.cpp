class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xr=0;
        for(auto it:nums) xr^=it;
        int diff=xr^k;
        return __builtin_popcount(diff);
    }
};