class Solution {
public:
    void dfs(int i,vector<vector<int>>& iscon, vector<bool>& vis){
        vis[i]=1;
        for(int j=0;j<iscon.size();j++){
            if(iscon[i][j]==1 && !vis[j]){
                dfs(j,iscon,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& iscon) {
        int n=iscon.size();
        vector<bool>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]) {
                ans++;
                dfs(i,iscon,vis);
            }
        }
        return ans;
    }
};