class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        long long rem=sum%p;
        if(rem==0) return 0;
        mpp[0]=-1;
        int ans=INT_MAX;
        long long pre=0;
        for(int i=0;i<n;i++){
            pre+=nums[i];
            int tar=(pre%p-rem+p)%p;
            if(mpp.find(tar)!=mpp.end()){
                ans=min(ans,i-mpp[tar]);
            }
            mpp[pre%p]=i;
        }
        if(ans==INT_MAX || ans==n) return -1;
        return ans;        
    }
};