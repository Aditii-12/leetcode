class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int p=0;
        while(nums[p]!=k) p++;
        unordered_map<int,int>cnt;
        int bal=0;
        cnt[0]=1;
        for(int i=p+1;i<n;i++){
            if(nums[i]>k) bal++;
            else bal--;
            cnt[bal]++;
        }
        int ans=0;
        bal=0;
        for(int i=p;i>=0;i--){
            if(nums[i]>k) bal++;
            else if(nums[i]<k) bal--;
            ans+=cnt[-bal];
            ans+=cnt[1-bal];
        }
        return ans;
    }
};