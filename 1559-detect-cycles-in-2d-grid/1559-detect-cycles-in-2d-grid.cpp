class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,-1,1};
    bool dfs(int r,int c,int pr,int pc,vector<vector<char>>& grid,vector<vector<int>>& vis){
        int m=grid.size();
        int n=grid[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr<0 || nc<0 || nr>=m || nc>=n) continue;
            if(grid[nr][nc]!=grid[r][c]) continue;
            if(nr==pr && nc==pc) continue;
            if(vis[nr][nc]==1) return 1;
            if(dfs(nr,nc,r,c,grid,vis)) return 1;
        }
        return 0;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,grid,vis)) return 1;
                }
            }
        }
        return 0;
    }
};