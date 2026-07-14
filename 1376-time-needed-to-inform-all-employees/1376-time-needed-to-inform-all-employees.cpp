class Solution {
public:
    vector<vector<int>>adj;
    int ans=0;
    void dfs(int node,int time,vector<int>& informtime){
        ans=max(ans,time);
        for(auto it:adj[node]){
            dfs(it,time+informtime[node],informtime);
        }
    }
    int numOfMinutes(int n, int headid, vector<int>& man, vector<int>& informtime) {
        adj.resize(n);
        for(int i=0;i<n;i++){
            if(man[i]!=-1){
                adj[man[i]].push_back(i);
            }
        }
        dfs(headid,0,informtime);
        return ans;
    }
};