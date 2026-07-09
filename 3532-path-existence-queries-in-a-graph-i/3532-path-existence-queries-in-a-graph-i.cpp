class Solution {
public:

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxd, vector<vector<int>>& queries) {
        vector<int>comp(n,0);
        int compno=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxd){
                compno++;
            }
            comp[i]=compno;
        }
        vector<bool>ans;
        for(auto it:queries){
            if(comp[it[0]]==comp[it[1]]) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};