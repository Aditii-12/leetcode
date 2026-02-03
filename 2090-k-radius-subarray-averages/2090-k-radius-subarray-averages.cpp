class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int m=2*k+1;
        int n=nums.size();
        vector<int>ans(n,-1);
        if(n<m) return ans;
        long long sum=0;
        int l=0;
        int r=0;
        while(r<n){
            sum+=nums[r];
            while(r-l+1>m){
                sum-=nums[l];
                l++;
            }
            if(r-l+1==m){
                ans[l+k]=sum/m;
            }
            r++;
        }
        return ans;
    }
};