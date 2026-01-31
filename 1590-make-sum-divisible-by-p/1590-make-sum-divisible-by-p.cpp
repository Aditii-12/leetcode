class Solution {
public:
    int minSubarray(vector<int>& nums, int k) {
        long long tot=0;
        for(auto it:nums){
            tot+=it;
        }
        long long rem=tot%k;
        if(rem==0) return 0; //already divisible h
        unordered_map<int,int>mpp; //last seen where
        mpp[0]=-1;

        int sum=0; //to prefix sum
        int ans=nums.size(); //worst case
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int target=(sum%k -rem+k)%k; //to handle negative case
            if(mpp.find(target)!=mpp.end()){
                ans=min(ans,i-mpp[target]);
            }
            mpp[(sum%k)]=i; //always store bdi index tbi length choti ayegi
        }
        return ans==nums.size()?-1:ans;

    }
};