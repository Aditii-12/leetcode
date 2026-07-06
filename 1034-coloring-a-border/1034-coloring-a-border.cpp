class Solution {
public:
    int dr[4]={0,0,-1,1};
    int dc[4]={-1,1,0,0};
    vector<pair<int,int>> borders;
    vector<vector<int>> vis;
    int colr; 
    int m,n;
    void dfs(int r,int c,vector<vector<int>>&grid){
        vis[r][c]=1;
        bool f=0;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr<0||nc<0||nr>=m||nc>=n){
                f=1;
                continue;
            }
            if(grid[nr][nc]!=colr){
                f=1;
                continue;
            }

            if(!vis[nr][nc]) dfs(nr,nc,grid);
        }
        if(f==1) borders.push_back({r,c});
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m=grid.size();
        n=grid[0].size();
        vis.assign(m,vector<int>(n,0));
        colr=grid[row][col];
        dfs(row,col,grid);
        for(auto [r,c]:borders)
            grid[r][c]=color;
        
        return grid;
    }
};