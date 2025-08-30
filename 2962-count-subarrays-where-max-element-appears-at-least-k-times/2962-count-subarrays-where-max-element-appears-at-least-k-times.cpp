class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxele=*max_element(nums.begin(),nums.end());
        int l=0,r=0;
        int n=nums.size();
        long long loba=0;
        int count=0;
        while(r<n){
            if(nums[r]==maxele) count++;
            while(count>=k){
                if(nums[l]==maxele) count--;
                l++;
            }
            loba+=l;
            r++;
        }
        return loba;
    }
};