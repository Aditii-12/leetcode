class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        int ans=INT_MAX;
        int sum=0;
        map<int,int>mpp;
        while(r<n){
            if(mpp[nums[r]]==0){
                sum+=nums[r];
            }
            mpp[nums[r]]++;

            while(sum>=k){
                if(mpp[nums[l]]==1){
                    sum-=nums[l];
                }
                ans=min(ans,r-l+1); //abi l ko kam ni kiya h
                mpp[nums[l]]--;
                l++;
            }
            r++;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};