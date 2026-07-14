class Solution {
public:
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};
    int maxDistance(vector<vector<int>>& grid) {
        int n =grid.size();
        queue<pair<int,int>>q;
        int l=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    l++;
                    q.push({i,j});
                }
            }
        }
        if(l==0 || l==n*n) return -1;
        int dist=-1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto [r,c]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr<0 || nc<0 || nc>=n || nr>=n ) continue;
                    if(grid[nr][nc]==1) continue;
                    grid[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
            dist++;
        }
        return dist;
    }
};