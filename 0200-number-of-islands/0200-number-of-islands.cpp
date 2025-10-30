class Solution {
public:
int n,m;
int dr[4]={0,0,-1,1};
int dc[4]={-1,1,0,0};
    void dfs(int i,int j,vector<vector<char>>& grid){
        grid[i][j]='0';
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m&& grid[nr][nc]=='1') 
            dfs(nr,nc,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1') {
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};