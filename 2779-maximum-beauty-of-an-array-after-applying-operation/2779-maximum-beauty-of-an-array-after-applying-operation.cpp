class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int i=0;
        int j=0;
        while(j<nums.size()){
            while(nums[j]-nums[i]>2*k) i++;
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};