class Solution {
public:
    long long dfs(int node,vector<vector<int>>& adj,vector<bool>&vis){
        vis[node]=1;
        long long area=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                area+=dfs(it,adj,vis);
            }
        }
        return area;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,0);
        vector<long long>sizes;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                sizes.push_back(dfs(i,adj,vis));
            }
        }
        long long ans=0;
        long long rem=n;
        for(int i=0;i<sizes.size();i++){
            ans+=(sizes[i]*(rem-sizes[i]));
            rem-=sizes[i];
        }
        return ans;

    }
};