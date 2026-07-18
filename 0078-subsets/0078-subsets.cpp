class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    int n;
    void func(int idx,vector<int>& nums){
        if(idx==n){
            ans.push_back(path);
            return;
        }
        path.push_back(nums[idx]);
        func(idx+1,nums);
        path.pop_back();
        func(idx+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        func(0,nums);
        return ans;
    }
};