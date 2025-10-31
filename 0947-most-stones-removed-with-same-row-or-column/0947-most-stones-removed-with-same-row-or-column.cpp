class Solution {
public:
    void dfs(vector<vector<int>>& adjl,vector<bool>& vis,int stone){
        vis[stone]=1;
        for(int neigh:adjl[stone]){
            if(vis[neigh]!=1) dfs(adjl,vis,neigh);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>>adjl(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<bool>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                dfs(adjl,vis,i);
                ans++;
            }
        }
        return n-ans;
    }
};