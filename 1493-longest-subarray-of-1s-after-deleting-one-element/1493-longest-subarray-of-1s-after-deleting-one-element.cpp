class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int countzero = 0;
        int maxi = 0;
        int n = nums.size();
        while (r < n) {

            if (nums[r] == 0)
                countzero++;
            while (countzero > 1) {
                if (nums[l] == 0)
                    countzero--;
                l++;
            }
            maxi = max(maxi, r - l );
            r++;
        }
        return maxi;
    }
};