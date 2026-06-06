class Solution {
public:
    void dfs(int node,int src,vector<vector<int>>&adj,vector<bool>& vis, vector<vector<int>>&ans){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                ans[it].push_back(src);
                dfs(it,src,adj,vis,ans);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto& it:edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            vector<bool>vis(n,0);
            dfs(i,i,adj,vis,ans);
        }
        return ans;
    }
};