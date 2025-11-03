class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
            nums[i]=nums[i]*nums[i];
        sort(nums.rbegin(),nums.rend());
        int mid;
        if(n%2==0)
            mid=n/2;
        else mid=n/2+1;
        long long ans=0;
        for(int i=0;i<mid;i++)
            ans+=nums[i];
        for(int i=mid;i<n;i++)
            ans-=nums[i];
        return ans;  
    }
};