class Solution {
public:
    void dfs(int node,vector<vector<int>>& adjl,vector<bool>&vis){
        vis[node]=1;
        for(auto neigh:adjl[node])
            if(vis[neigh]==0)
                dfs(neigh,adjl,vis);
        
    }
    int findCircleNum(vector<vector<int>>& adjm) {
        int n=adjm.size();
        vector<vector<int>>adjl(n);
        vector<bool> vis(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adjm[i][j]==1 & i!=j)
                adjl[i].push_back(j);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                ans++;
                dfs(i,adjl,vis);
            }
        }
        return ans;

    }
};