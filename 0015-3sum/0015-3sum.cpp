class Solution {
public:
    void func(int tar,int k,vector<int>& nums,vector<vector<int>>& ans){
        int i=k;
        int j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]<tar) i++;
            else if(nums[i]+nums[j]>tar) j--;
            else{
                ans.push_back({-tar,nums[i],nums[j]});
                while(i<j && nums[i]==nums[i+1]) i++;
                while(i<j && nums[j]==nums[j-1]) j--;
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if (n<3) return {};
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int tar=-nums[i];
            if(i!=0 && nums[i]==nums[i-1]) continue;
            func(tar,i+1,nums,ans);
        }
        return ans;
    }
};