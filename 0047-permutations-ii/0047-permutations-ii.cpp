class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    vector<bool>used;
    void func(vector<int>& nums){
        if(path.size()==nums.size()){
            ans.push_back(path);
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;
            path.push_back(nums[i]);
            used[i]=1;
            func(nums);
            used[i]=0;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        used.resize(nums.size(),0);
        func(nums);
        return ans;
    }
};