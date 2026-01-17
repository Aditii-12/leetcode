class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diff(n+1,0);
        for(auto it:queries){
            diff[it[0]]--;
            diff[it[1]+1]++;
        }
        int curr=0;
        for (int i=0;i<n;i++) {
            curr+=diff[i];          
            if (nums[i]+curr>0)  
                return 0;
        }
        return 1;
        
    }
};