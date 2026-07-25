class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int sum=0;
        mpp[0]=1;
        for(auto it:nums){
            sum+=it;
            mpp[((sum%k)+k)%k]++;
        }
        int cnt=0;
        for(auto it:mpp){
            int x=it.second;
            cnt+=(x)*(x-1)/2;
        }
        return cnt;
    }
};