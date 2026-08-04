class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int l=nums[0];
        for(int i=1;i<nums.size();i++){
            while(nums[i]>l+1){
                ans.push_back(l+1);
                l++;
            }
            l=nums[i];
        }
        return ans;
    }
};