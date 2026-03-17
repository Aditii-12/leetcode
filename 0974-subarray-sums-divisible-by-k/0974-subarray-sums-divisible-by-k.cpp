class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mpp[(sum%k+k)%k]++;
        }
        for(auto it:mpp){
            if(it.second>1) 
                ans+=it.second*(it.second-1)/2;
        }
        return ans;
    }
};