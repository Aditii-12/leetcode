class Solution {
public:
int dr[4]={1,-1,0,0};
int dc[4]={0,0,-1,1};
    bool func(int mid,vector<vector<int>>& dist){
        int n=dist.size();
        if(dist[0][0]<mid) return 0;
        queue<pair<int,int>> q;
        vector<vector<int>>vis(n,vector<int>(n,0));
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty()) {
            auto[r,c]=q.front();
            q.pop();
            if(r==n-1 && c==n-1)
                return 1;
            for(int i=0;i<4;i++) {
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr<0||nc<0|| nr>=n || nc>=n) continue;
                if(vis[nr][nc]) continue;
                if(dist[nr][nc]<mid)continue;
                vis[nr][nc] = 1;
                q.push({nr,nc});
            }
        }
        return 0;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nc=c+dc[i];
                int nr=r+dr[i];
                if(nc<0 || nr<0 || nc>=n || nr>=n) continue;
                if(dist[nr][nc]!=-1) continue;
                dist[nr][nc]=dist[r][c]+1;
                q.push({nr,nc});
            }
        }
        int l=0,h=2*n;
        int ans=0;
        while(l<=h){
            int m=l+(h-l)/2;
            if(func(m,dist)){
                ans=m;
                l=m+1;
            }
            else h=m-1;
        }
        return ans;
    }
};