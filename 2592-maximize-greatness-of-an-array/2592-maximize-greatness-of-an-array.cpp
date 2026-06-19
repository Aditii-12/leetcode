class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            if(nums[j]>nums[i]){
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};