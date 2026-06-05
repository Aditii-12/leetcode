class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,-1,1};
    bool dfs(int r,int c,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(r<0||c<0||r>=n||c>=m) return 0; //it means that 0 cell was on boundary
        //and its neighbours is out of bound
        if(grid[r][c]==1) return 1;
        grid[r][c]=1;
        bool up=dfs(r-1,c,grid);
        bool down=dfs(r+1,c,grid);
        bool le=dfs(r,c-1,grid);
        bool ri=dfs(r,c+1,grid);
        return  up && down && le && ri;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    if(dfs(i,j,grid))
                        ans++;
                }
            }
        }
        return ans;
    }
};