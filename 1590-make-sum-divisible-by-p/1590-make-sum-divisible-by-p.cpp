class Solution {
public:
    using ll=long long;
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        ll sum=accumulate(nums.begin(),nums.end(),0LL);
        unordered_map<int,int>mpp;
        ll rem=sum%p;
        if(rem==0) return 0;
        mpp[0]=-1;
        int ans=INT_MAX;
        sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int tar=(sum%p-rem+p)%p;
            if(mpp.find(tar)!=mpp.end()){
                ans=min(ans,i-mpp[tar]);
            }
            mpp[sum%p]=i;
        }
        if(ans==INT_MAX||ans==n) return -1;
        return ans;
        
    }
};