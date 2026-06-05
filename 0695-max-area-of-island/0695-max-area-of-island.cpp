class Solution {
public:
    int dr[4]={0,0,-1,1};
    int dc[4]={1,-1,0,0};
    int ans=0;
    int dfs(int r,int c,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        int area=1;
        if(r<0||c<0||r>=n||c>=m) return 0;
        if(grid[r][c]==0) return 0;
        grid[r][c]=0;
        for(int i=0;i<4;i++){
            area+=dfs(r+dr[i],c+dc[i],grid);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) {
                    int area=dfs(i,j,grid);
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
};