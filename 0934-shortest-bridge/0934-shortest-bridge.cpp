class Solution {
public:
    int dr[4]={0,0,-1,1};
    int dc[4]={1,-1,0,0};
    void dfs(int r,int c,vector<vector<int>>& grid,queue<pair<int,int>> &q){
        int n=grid.size();
        if(r<0 || c<0 || r>=n || c>=n) return;
        if(grid[r][c]!=1) return;
        grid[r][c]=2;
        q.push({r,c});
        for(int i=0;i<4;i++){
            dfs(r+dr[i],c+dc[i],grid,q);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>>q;
        bool f=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) {
                    f=1;
                    dfs(i,j,grid,q);
                    break;
                }
            }
            if(f==1) break;  
        }
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<0 || nc<0 || nr>=n || nc>=n){
                    continue;
                }
                if(grid[nr][nc]==2) continue;
                if(grid[nr][nc]==1) return steps;
                grid[nr][nc]=2;
                q.push({nr,nc});
            }
            }
            steps++;
        }
        return -1;

    }
};