using ll=long long;
class Solution {
public:
    int dfs(int node,vector<bool>& vis,vector<vector<int>>& adj){
        vis[node]=1;
        int cnt=1;
        for(auto it:adj[node]){
            if(!vis[it])
                cnt+=dfs(it,vis,adj);
        }
        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            ll x1=bombs[i][0];
            ll y1=bombs[i][1];
            ll r=bombs[i][2];
            for(int j=0;j<n;j++){    
                if(i==j) continue;
                ll x2=bombs[j][0];
                ll y2=bombs[j][1];
                ll dx=x2-x1;
                ll dy=y2-y1;
                ll dis=dx*dx+dy*dy;
                if(dis<=r*r){
                    adj[i].push_back(j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            vector<bool>vis(n,0);
            ans=max(ans,dfs(i,vis,adj));
        }
        return ans;
    }
};