class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        long long ans=LLONG_MIN;
        long long mini=nums[0];
        long long maxi=nums[0];
        int j=m-1;
        while(j<n){
            mini=min(mini,(long long)nums[j-m+1]);
            maxi=max(maxi,(long long)nums[j-m+1]);
            ans=max(ans,max(nums[j]*mini,nums[j]*maxi));
            j++;
        }
        return ans;
    }
};