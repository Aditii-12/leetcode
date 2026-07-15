class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            mpp[((sum%k)+k)%k]++;
        }
        for(auto it:mpp){
            ans+=(it.second-1)*it.second/2;
        }
        return ans;

    }
};