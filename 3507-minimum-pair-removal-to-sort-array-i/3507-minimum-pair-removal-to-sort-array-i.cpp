class Solution {
bool issorted(vector<int> nums){
    for(int i=1;i<nums.size();i++){
        if(nums[i]<nums[i-1]) return false;
    }
    return true;
}
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans=0;
        while(!issorted(nums)){
            int msum=INT_MAX;
            int index=-1;
            for(int i=0;i<nums.size()-1;i++){
                int sum=nums[i]+nums[i+1];
                if(sum<msum){
                    msum=sum;
                    index=i;
                }
            }
            nums[index]=nums[index]+nums[index+1];
            nums.erase(nums.begin()+index+1);
            ans++;
        }
        return ans;
        
        
    }
};