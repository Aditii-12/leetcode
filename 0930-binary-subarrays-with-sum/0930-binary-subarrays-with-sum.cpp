class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int r=0,l=0;
        int cnt=0;
        int sum=0;
        while(r<n){
            sum+=nums[r];
            int zcnt=0;
            while(l<r && sum>goal) {
                sum-=nums[l];
                l++;
            }
            if(sum==goal){
            int j=l;
            while(nums[j]==0&&j<r){
                j++;
                zcnt++;
            }
            cnt+=(zcnt+1);
            }
            r++;
        }
        return cnt;
    }
};