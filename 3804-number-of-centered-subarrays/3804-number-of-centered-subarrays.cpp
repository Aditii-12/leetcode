class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<long long,int>mpp;
            long long sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                mpp[nums[j]]++;
                if(mpp.count(sum)) ans++;
            }
        }
        return ans;
    }
};