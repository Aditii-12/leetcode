class Solution {
public:
    int dr[4]={0,0,-1,1};
    int dc[4]={1,-1,0,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int time=0;
        while(!q.empty()){
            bool f=0;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto it=q.front();
                auto r=it.first;
                auto c=it.second;
                q.pop();
                for(int j=0;j<4;j++){
                    int nr=r+dr[j];
                    int nc=c+dc[j];
                    if(nr<0 || nc<0 || nr>=m || nc>=n) continue;
                    if(grid[nr][nc]==1) {
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        f=1;
                    }
                }
            }
            if(f==1) time++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};