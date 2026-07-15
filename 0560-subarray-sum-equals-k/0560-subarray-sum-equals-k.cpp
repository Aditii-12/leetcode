class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        mpp[0]=1;
        int sum=0;
        int ans=0;
        for(auto it:nums){
            sum+=it;
            if(mpp.find(sum-k)!=mpp.end()){
                ans+=mpp[sum-k];
            }
            mpp[sum]++;
        }
        return ans;
    }
};