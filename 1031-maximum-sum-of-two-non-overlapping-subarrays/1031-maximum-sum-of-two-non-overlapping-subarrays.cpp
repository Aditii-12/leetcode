class Solution {
public:
    int solve(vector<int>& nums,vector<int>& pre, int x,int y){
        int n=nums.size();
        int maxi=0; //first lemgth jo h uska max sum
        int ans=0; //overall
        for(int i=x+y;i<=n;i++){
            int sumx=pre[i-y]- pre[i-x-y];
            maxi=max(maxi,sumx);

            //curr y subarray
            int sumy=pre[i]-pre[i-y];
            ans=max(ans,maxi+sumy);
        }
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int fl, int sl) {
        int n=nums.size();
        vector<int>pre(n+1,0);
        pre[0]=nums[0];
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
        }
        int op1=solve(nums,pre,fl,sl); //pehle first length then second length
        int op2=solve(nums,pre,sl,fl); //ulta

        return max(op1,op2);
    }
};