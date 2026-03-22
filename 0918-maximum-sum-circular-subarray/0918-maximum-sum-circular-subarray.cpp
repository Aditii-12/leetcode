class Solution {
public:
    int kadanemax(vector<int>& nums, int n) {
        int sum=0;
        int maxs=nums[0];
        
        for(int i=0;i<n;i++) {
            sum+=nums[i];
            maxs=max(maxs,sum);
            if(sum<0) sum=0;
        }
        return maxs;
    }
    int kadanemin(vector<int>& nums,int n){
        int sum=nums[0];
        int mini=nums[0];
        for(int i=1;i<n;i++){
            sum=min(sum+nums[i],nums[i]);
            mini=min(mini,sum);
        }
        return mini;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0LL);
        int maxsu=kadanemax(nums,n);
        int minsu=kadanemin(nums,n);
        int circu=sum-minsu;
        if(maxsu>0){ //if atleast one eleemnt is +ve. else if all are -ve circu will give 0 
            return max(circu,maxsu); 
        }
        return maxsu; //if all elements ar -ve

    }
};