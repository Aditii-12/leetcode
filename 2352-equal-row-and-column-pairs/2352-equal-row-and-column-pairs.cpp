class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        map<vector<int>,int>freq;
        for(auto it:grid){
            freq[it]++;
        }
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[j][i]);
            }
            ans+=freq[temp];
        }
        return ans;
    }
};