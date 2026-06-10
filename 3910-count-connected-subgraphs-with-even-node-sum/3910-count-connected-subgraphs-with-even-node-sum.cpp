class Solution {
public:
    int dfs(int i,int node,vector<vector<int>>& adj,vector<bool>&vis){
        vis[node]=1;
        int cnt=1;
        for(int v:adj[node]){
            if(!(i&(1<<v))) continue;
            if(!vis[v]){
                cnt+=dfs(i,v,adj,vis);
            }
        }
        return cnt;
    }
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        for(int i=1;i<(1<<n);i++){
            int sum=0;
            int st=-1;
            int nodes=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)) {
                    sum+=nums[j];
                    nodes++;
                    if(st==-1) st=j;
                }
            }
            if(sum%2==1) continue;
            vector<bool>vis(n,0);
            int cnt=dfs(i,st,adj,vis);
            if(cnt==nodes) ans++;
        }
        return ans;
    }
};