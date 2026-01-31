class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int ans=0;
        map<int,int>mpp; //in this we store first occurence of cnt
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