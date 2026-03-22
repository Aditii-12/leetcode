class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int dp0=nums[0]; //max sum without any deletion
        int dp1=0; //
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            dp1=max(dp0,dp1+nums[i]);
            dp0=max(dp0+nums[i],nums[i]);
            ans=max(ans,max(dp0,dp1));
        }
        return ans;
    }
};