class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        int a= 1,b= 0,res = 0;
        for (int i=1;i<n;i++) {
            if (nums[i]>nums[i-1]) a++;
            else {
                b=a;
                a=1;
            }
            int h=a>>1;
            int m =min(a,b);
            int ans= max(h, m);
            if (ans> res) res =ans;
        }
        return res;
    }
};