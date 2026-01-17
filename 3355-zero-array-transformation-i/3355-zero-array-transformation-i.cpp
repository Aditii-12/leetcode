class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int>diff(n+1,0);
        for(auto it:queries){
            int l=it[0];
            int r=it[1];
            diff[l]--;
            diff[r+1]++;
        }
        int curr = 0;
        for (int i=0;i<n;i++) {
            curr+=diff[i];          
            if (nums[i]+curr>0)  
                return 0;
        }
        return 1;
        
    }
};