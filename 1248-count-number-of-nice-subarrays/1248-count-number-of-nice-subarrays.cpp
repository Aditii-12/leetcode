class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int odd=0;
        int ans=0;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1) odd++;
            if(mpp.find(odd-k)!=mpp.end()){
                ans+=mpp[odd-k];
            }
            mpp[odd]++;
        }
        return ans;
    }
};