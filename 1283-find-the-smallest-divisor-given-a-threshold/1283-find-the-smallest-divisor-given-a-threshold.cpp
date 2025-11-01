class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l= 1;
        int h=*max_element(nums.begin(), nums.end());
        int ans=0;
        while (l<=h) {
            int m=(l+h)/2;
            int s=0;
            for (int i=0;i<n;i++) {
                // sum = sum + ceil((double)nums[i] / (double)mid);
                s+=(nums[i]+m-1)/m;
            }
            if (s<=threshold) {
                h=m-1;
                ans=m;
            } else 
                l=m+1;
        }
        return ans;
    }
};