class Solution {
public:
int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};
int n,m;
    void dfs(int row,int col,vector<vector<bool>>&vis,vector<vector<int>>& grid){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=n || nr<0 || nc>=m || nc<0 || grid[nr][nc]==0 || vis[nr][nc]==1) continue;
            dfs(nr,nc,vis,grid);
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        //in this way we mark all islands connected to boundary 1
        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && vis[0][i]!=1){ //top row
                dfs(0,i,vis,grid);
            }
            if(grid[n-1][i]==1 && vis[n-1][i]!=1) //last row
                dfs(n-1,i,vis,grid);
        }
        for (int i= 0;i<n;i++){
            if(grid[i][0]==1 && vis[i][0]!=1) //first col
                dfs(i,0,vis,grid);
            if(grid[i][m-1]==1 && vis[i][m-1]!=1) //last col
                dfs(i,m-1,vis,grid);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0) 
                    ans++;
            }
        }
    return ans;
    }
};