class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        int sum=0;
        mpp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int temp=sum%k;
            if(mpp.find(temp)!=mpp.end()){
                if(i-mpp[temp]>=2) return 1;
            }
            else mpp[temp]=i;
        }
        return 0;
    }
};