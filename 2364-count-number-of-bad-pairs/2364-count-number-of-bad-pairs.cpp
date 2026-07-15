class Solution {
public:
    using ll=long long;
    long long countBadPairs(vector<int>& nums) {
        ll n=nums.size();
        ll t=(n)*(n-1)/2;
        ll g=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            g+=mpp[nums[i]-i];
            mpp[nums[i]-i]++;
        }
        return t-g;
    }
};