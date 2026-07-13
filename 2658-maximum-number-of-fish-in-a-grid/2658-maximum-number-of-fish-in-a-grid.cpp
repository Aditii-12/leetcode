class Solution {
public:
    int dr[4]={0,0,-1,1};
    int dc[4]={1,-1,0,0};
    int dfs(int r,int c,vector<vector<int>>&g){
        int cnt=0;
        cnt+=g[r][c];
        g[r][c]=0;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr<0 || nc<0 || nr>=g.size() || nc>=g[0].size()) continue;
            if(g[nr][nc]!=0)
                cnt+=dfs(nr,nc,g);
        }
        return cnt;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0) ans=max(ans,dfs(i,j,grid));
            }
        }
        return ans;
    }
};