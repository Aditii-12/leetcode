class Solution {
public:
int subarraySum(vector<int>& nums,int k){
    map<int,int> mpp;
    mpp[0]=1;
    int presum=0,count=0;
    for(auto i:nums) {
        presum+=i;
        int r=presum-k;
        count+=mpp[r];
        mpp[presum]+=1;
    }
    return count;
}
};