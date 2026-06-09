class Solution {
public:
    int dr[4]={0,0,-1,1};
    int dc[4]={1,-1,0,0};
    long long dfs(int r,int c,vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(r<0 || c<0 || r>=m || c>=n) return 0;
        if(grid[r][c]==0) return 0;
        long long sum=grid[r][c];
        grid[r][c]=0;
        for(int i=0;i<4;i++){
            sum+=dfs(r+dr[i],c+dc[i],grid);
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    long long sum=dfs(i,j,grid);
                    if(sum%k==0) ans++;
                }
            }
        }
        return ans;
    }

};