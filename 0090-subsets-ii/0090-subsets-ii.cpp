class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    void func(int idx,vector<int>& nums){
        ans.push_back(path);
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            func(i+1,nums);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        func(0,nums);
        return ans;
    }
};