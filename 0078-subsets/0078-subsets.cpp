class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=(1<<nums.size());
        for(int i=0;i<n;i++){ //total subsets 
            vector<int>temp;
            for(int j=0;j<nums.size();j++)
            { //to check if jth bit is set or not
            if(i & (1<<j)) 
                temp.push_back(nums[j]);
            }
            ans.push_back(temp);

        }
        return ans;
    }
};