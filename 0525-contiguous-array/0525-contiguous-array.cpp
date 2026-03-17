class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        unordered_map<int,int>mpp;
        int ans=0;
        mpp[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0) cnt--;
            else cnt++;
            if(mpp.find(cnt)!=mpp.end()){
                ans=max(ans,i-mpp[cnt]);
            }
            else mpp[cnt]=i;
        }
        return ans;
    }
};