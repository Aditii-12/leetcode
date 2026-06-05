class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,1,-1};
    void dfs(int r,int c,vector<vector<char>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(r<0||c<0||r>=m||c>=n) return;
        if(grid[r][c]=='0') return;
        grid[r][c]='0';
        for(int i=0;i<4;i++){
                dfs(r+dr[i],c+dc[i],grid);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};