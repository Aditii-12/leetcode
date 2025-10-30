class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int ans=0;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        while(!q.empty()){
            int size=q.size();
            bool f=0; //to check if there is any orange rotting at that min
            for(int i=0;i<size;i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=row+dr[i];
                    int nc=col+dc[i];
                    if(nr>=0&&nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                        q.push({nr,nc});
                        grid[nr][nc]=2;
                        f=1;
                    }
                }
            }
            if (f==1) ans++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;

    }
};