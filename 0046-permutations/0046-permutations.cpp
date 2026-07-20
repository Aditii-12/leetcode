class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    vector<bool>used;
    void func(vector<int>& nums){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==1) continue;
            path.push_back(nums[i]);
            used[i]=1;
            func(nums);
            used[i]=0;
            path.pop_back();
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size());
        func(nums);
        return ans;
    }
};