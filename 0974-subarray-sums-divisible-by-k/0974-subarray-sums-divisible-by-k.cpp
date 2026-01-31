class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mpp;
        mpp[0]=1; //rem 0 appears 1 time
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int st=(sum%k+k)%k; //to abvoid neg
            mpp[st]++;
        }
        int ans=0;
        for(auto it:mpp){
            ans+=(it.second)*(it.second-1)/2;
        }
        return ans;
    }
};