class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=k;
        while (i<nums.size()) {
            if (nums[i]<j) {
                i++;
            }
            else if(nums[i]==j) {
                j+=k;
                i++;
            }
            else {
                return j;
            }
        }
        return j;
    }
};