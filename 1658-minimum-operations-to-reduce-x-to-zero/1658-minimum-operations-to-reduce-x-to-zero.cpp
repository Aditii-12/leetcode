class Solution {
public:
//what we need to keep in our array
//total sum of array-x ==target(ye hme array me rkhna h)
//so we see array of sum target of max length possible
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        for(auto &it:nums) sum+=it;
        int target=sum-x;
        if(target<0) return -1;
        if(target==0) return n; //sare hi htane pdenge
        int ans=-1;
        int summ=0;
        int l=0;
        int r=0;
        while(r<n){
            summ+=nums[r];
            while(summ>target && l<=r){
                summ-=nums[l];
                l++;
            }
            if(summ==target){
                ans=max(ans,r-l+1);
            }
            r++;
        }
        if(ans==-1) return -1;
        return n-ans;
    }
};