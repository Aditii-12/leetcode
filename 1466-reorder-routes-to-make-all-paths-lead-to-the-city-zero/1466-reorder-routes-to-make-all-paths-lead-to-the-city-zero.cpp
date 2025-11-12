class Solution {
public:
    int cnt=0;
    void dfs(int node,int par,vector<vector<pair<int,int>>>&adj){
        for(auto& [neigh,sign]:adj[node]){
            if(neigh!=par){
                cnt+=sign;
                dfs(neigh,node,adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& c) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& it:c){
            adj[it[0]].push_back({it[1],1});
            adj[it[1]].push_back({it[0],0});
        }
        dfs(0,-1,adj);
        return cnt;
    }
};