class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxele=*max_element(nums.begin(),nums.end());
        int l=0,r=0;
        int n=nums.size();
        long long ans=0;
        int freq=0;
        while(r<n){
            if(nums[r]==maxele) freq++;
            while(freq>=k){
                ans+=(n-r);
                if(nums[l]==maxele) freq--;
                l++;
            }
            r++;
        }
        return ans;

    }
};